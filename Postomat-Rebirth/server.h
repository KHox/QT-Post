#ifndef SERVER_H
#define SERVER_H

#include "product.h"
#include "receiveddata.h"
#include "productinfo.h"
#include <QString>
#include <QFile>
#include <QTextCodec>
#include <QDebug>
#include <list>
#include <QDir>

class Server
{
public:
    Server();

    ProductInfo* GetProductInfo(QString code, int& cell);
    ReceivedData* GetReceived(QString code);
    Server& SaveConfig();
    Server& SaveReceived();
    Server& SetReceived(int index, QString status);
    Product* ReadProduct(QString code);

    bool Connect(QString login, QString pass);
    void Disconnect();

    int CellsCount() { return cellsCount; }
    ProductInfo** ProductList() { return productList; }
    std::list<ReceivedData>& ReceivedProducts() { return receivedProducts; }

    int AddProductInfo(ProductInfo& p);

private:
    int cellsCount = 10;
    ProductInfo** productList = new ProductInfo*[10];
    std::list<ReceivedData> receivedProducts;

    QString configName = "serverConfig.txt";
    QString received = "received.txt";
    QString staffMembers = "lpConfig.txt";

    QString log;
    QString pass;
};

#endif // SERVER_H
