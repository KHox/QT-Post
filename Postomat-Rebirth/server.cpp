#include "server.h"

Server::Server()
{
    QTextCodec::setCodecForLocale( QTextCodec::codecForName( "UTF-8" ) );

    for (int i = 0; i < cellsCount; i++)
    {
        productList[i] = NULL;
    }

    QFile recFile(received);
    if (recFile.open(QIODevice::ReadOnly)) {
        QTextStream stream( &recFile );

        QString str;
        int debugI = 0;
        while (stream.readLineInto(&str))
        {
            receivedProducts.push_back(ReceivedData(str));
            debugI++;
        }

        recFile.close();
        qDebug() << "Loaded " << debugI << " received products\n";
    }


    QFile config(configName);
    if (config.open(QIODevice::ReadOnly)) {
        QTextStream stream( &config );
        int count = stream.readLine().toInt();

        qDebug() << "Read config with" << count << "products";

        if (count > 0)
        {
            cellsCount = count;
            productList = new ProductInfo*[count];
            for (int i = 0; i < count; i++)
            {
                productList[i] = NULL;
            }

            int debugI = 0;
            QString str;

            while (stream.readLineInto(&str))
            {

                QStringList s = str.split("::");
                int ind = s[0].toInt();

                if (ind < cellsCount)
                {
                    auto pi = s[1].split(" ");

                    productList[ind] = new ProductInfo(ReadProduct(pi[0]), pi[1], pi[2]);

                    debugI++;
                }
                else
                {
                    qDebug() << "InitServer:Out of bounds:  " << ind <<
                                " out of " << cellsCount << "\n";
                }
            }

            config.close();
            qDebug() << "InitServer:Loaded " << debugI << " products!\n";
        }
        else
        {
            SaveConfig();
            qDebug() << "InitServer:Failed to load server config. New config is automatically created!\n";
        }
    }
    else
    {
        SaveConfig();
        qDebug() << "InitServer:Failed to load server config. New config is automatically created!\n";
    }
}

Server& Server::SaveConfig()
{
    QFile config(configName);
    if (config.open(QIODevice::WriteOnly))
    {
        qDebug() << "Saving config";
        QTextStream stream( &config );

        stream << cellsCount << "\n";

        for (int i = 0; i < cellsCount; i++)
        {
            if (productList[i] != NULL)
            {
                stream << i << "::" << productList[i]->ToString() << "\n";
            }
        }

        config.close();
    }
    else
    {
        qDebug() << "SaveConfig: " << configName << " cells: " << cellsCount << "\n";
    }
    return *this;
}

Server& Server::SaveReceived()
{
    QFile recFile(received);
    if (recFile.open(QIODevice::WriteOnly)) {
        QTextStream stream( &recFile );

        for (auto rData : receivedProducts)
        {
            stream << rData.ToString() << "\n";
        }

        recFile.close();
        qDebug() << "Server::SaveReceived: Saved " << receivedProducts.size() << " received products\n";
    }
    else
    {
        qDebug() << "Server::SaveReceived: Failed to open " << received << " file\n";
    }
    return *this;
}

Product* Server::ReadProduct(QString code)
{
    QFile pInfo(QDir::currentPath() + "/products/" + code + ".txt");

    if (pInfo.open(QIODevice::ReadOnly))
    {
        Product* p = new Product();
        QTextStream stream( &pInfo );
        stream.readAll() >> *p;
        p->code = code;
        pInfo.close();
        return p;
    }
    else
    {
        qDebug() << "Server::ReadProduct: Trying to read unknown product: " << code << "\n";
        return NULL;
    }
}

ProductInfo* Server::GetProductInfo(QString code, int& cell)
{
    for (int i = 0; i < cellsCount; i++)
    {
        if (productList[i] != NULL && productList[i]->product->code == code)
        {
            cell = i;
            return productList[i];
        }
    }

    qDebug() << "Server::GetProduct: Trying to get unknown product: " << code << "\n";
    return NULL;
}

Server& Server::SetReceived(int index, QString status)
{
    if (index < cellsCount)
    {
        receivedProducts.push_back(ReceivedData(productList[index]->product->code,
                                                status,
                                                productList[index]->arrivalDate,
                                                QDateTime::currentDateTime()));
        productList[index] = NULL;
        SaveReceived();
        SaveConfig();
    }
    else
    {
        qDebug() << "Server::SetReceived:Trying to receiv out of bounds product: " << index << "\n";
    }

    return *this;
}

bool Server::Connect(QString login, QString pass)
{
    QFile lpdb(staffMembers);

    if (lpdb.open(QIODevice::ReadOnly)) {
        QTextStream stream( &lpdb );

        QString str;
        while (stream.readLineInto(&str))
        {
            auto s = str.split(" ");
            qDebug() << str;

            if (login == s[0] && pass == s[1])
            {
                this->log = login;
                this->pass = pass;
                lpdb.close();
                return true;
            }
        }

        lpdb.close();
        qDebug() << "Server::Connect: Unknown login or passwowrd: " << login << " " << pass << "\n";
    }
    else
    {
        qDebug() << "Server::Connect: Failed to open DB\n";
    }
    return false;
}

void Server::Disconnect()
{
    log = "";
    pass = "";
}

ReceivedData* Server::GetReceived(QString code)
{
    for (auto iter = receivedProducts.begin(); iter != receivedProducts.end(); iter++)
    {
        if (iter->code == code)
        {
            return &*iter;
        }
    }
    return NULL;
}

int Server::AddProductInfo(ProductInfo &p)
{
    for (int i = 0; i < cellsCount; i++)
    {
        if (productList[i] == NULL)
        {
            productList[i] = &p;
            SaveConfig();
            return i;
        }
    }

    return -1;
}
