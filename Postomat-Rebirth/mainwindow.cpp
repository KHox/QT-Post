#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    QIntValidator* validator = new QIntValidator(this);
    ui->lineEdit_1->setValidator(validator);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_3->setValidator(validator);
    ui->lineEdit_4->setValidator(validator);
    ui->lineEdit_5->setValidator(validator);
    ui->lineEdit_6->setValidator(validator);

    gif = new QMovie(":/img/img/loading-1.gif");
    server = new Server();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_userButton_clicked()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();

    ui->lineEdit_1->setFocus();

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_lineEdit_1_textEdited(const QString &arg1)
{
    if (arg1 != "") {
        QString code = GetCode();
        if (code.length() != 6)
        {
            ui->lineEdit_2->setFocus();
            ui->lineEdit_2->selectAll();
        }
        else
        {
            StartFind(code);
        }
    }
}

void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{
    if (arg1 != "") {
        QString code = GetCode();
        if (code.length() != 6)
        {
            ui->lineEdit_3->setFocus();
            ui->lineEdit_3->selectAll();
        }
        else
        {
            StartFind(code);
        }
    }
}

void MainWindow::on_lineEdit_3_textEdited(const QString &arg1)
{
    if (arg1 != "") {
        QString code = GetCode();
        if (code.length() != 6)
        {
            ui->lineEdit_4->setFocus();
            ui->lineEdit_4->selectAll();
        }
        else
        {
            StartFind(code);
        }
    }
}

void MainWindow::on_lineEdit_4_textEdited(const QString &arg1)
{
    if (arg1 != "") {
        QString code = GetCode();
        if (code.length() != 6)
        {
            ui->lineEdit_5->setFocus();
            ui->lineEdit_5->selectAll();
        }
        else
        {
            StartFind(code);
        }
    }
}

void MainWindow::on_lineEdit_5_textEdited(const QString &arg1)
{
    if (arg1 != "") {
        QString code = GetCode();
        if (code.length() != 6)
        {
            ui->lineEdit_6->setFocus();
            ui->lineEdit_6->selectAll();
        }
        else
        {
            StartFind(code);
        }
    }
}

void MainWindow::on_lineEdit_6_textEdited(const QString &arg1)
{
    if (arg1 != "") {
        QString code = GetCode();
        if (code.length() != 6)
        {
            ui->lineEdit_6->clearFocus();
        }
        else
        {
            StartFind(code);
        }
    }
}

QString MainWindow::GetCode()
{
    return ui->lineEdit_1->text() + ui->lineEdit_2->text() + ui->lineEdit_3->text() + ui->lineEdit_4->text() + ui->lineEdit_5->text() + ui->lineEdit_6->text();
}

void MainWindow::StartFind(QString code)
{
    ui->loadingLabel->setMovie(gif);
    gif->start();
    QTimer::singleShot(800, this, &MainWindow::ShowProductInfo);

    qDebug() << "Trying find product info";
    pi = server->GetProductInfo(code, currentCell);
    if (pi != NULL)
    {
        ui->nameLabel->setText(pi->product->name);
        ui->descriptionLabel->setText(pi->product->description);
        ui->priceLabel->setText(("Цена: " + pi->product->price));
        ui->cellInfoLabel->setText("Ячейка: " + QString::number(currentCell));

        QPixmap img(pi->product->link);
        int w = ui->productImg->width();
        int h = ui->productImg->height();

        ui->productImg->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));
    }
}

void MainWindow::ShowProductInfo()
{
    gif->stop();
    ui->loadingLabel->setMovie(NULL);
    if (pi != NULL)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        if (QMessageBox::question(this, "Ошибка!", "Несуществующий код товара.", "Ввести ещё раз", "Отмена"))
        {
            ui->stackedWidget->setCurrentIndex(0);
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(1);
        }
    }
}

void MainWindow::on_receivingButton_clicked()
{
    server->SetReceived(currentCell, "Получено");
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_cancelButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_confirmButton_clicked()
{
    bool flag = false;
    QString status = "Отменено: ";

    if (ui->checkBox->isChecked())
    {
        status += ui->checkBox->text();
        flag = true;
    }

    if (ui->checkBox_2->isChecked())
    {
        if (flag)
        {
            status += ", " + ui->checkBox_2->text();
        }
        else
        {
            flag = true;
            status += ui->checkBox_2->text();
        }
    }

    if (ui->checkBox_3->isChecked())
    {
        if (flag)
        {
            status += ", " + ui->checkBox_3->text();
        }
        else
        {
            flag = true;
            status += ui->checkBox_3->text();
        }
    }

    if (ui->checkBox_4->isChecked())
    {
        if (flag)
        {
            status += ", " + ui->checkBox_4->text();
        }
        else
        {
            flag = true;
            status += ui->checkBox_4->text();
        }
    }

    if (ui->checkBox_5->isChecked())
    {
        if (flag)
        {
            status += ", " + ui->checkBox_5->text();
        }
        else
        {
            status += ui->checkBox_5->text();
        }
    }

    server->SetReceived(currentCell, status);
    ui->stackedWidget->setCurrentIndex(4);
    QTimer::singleShot(10000, this, [=]() {ui->stackedWidget->setCurrentIndex(0);});
}


void MainWindow::on_staffButton_clicked()
{
    authWindow = new Auth(this);
    authWindow->setModal(true);
    authWindow->exec();

    if (authWindow->isAccepted)
    {
        if (server->Connect(authWindow->login, authWindow->password))
        {
            if (authWindow->login == "ADMIN" && authWindow->password == "123123")
            {
                ui->stackedWidget->setCurrentIndex(6);
            }
            else
            {
                ui->stackedWidget->setCurrentIndex(5);
            }
        }
        else
        {
            QMessageBox::critical(this, "Ошибка!", "Неверный логин или пароль.");
        }
    }
}



void MainWindow::on_backButton_clicked()
{
    server->Disconnect();
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_currentButton_clicked()
{
    ui->listWidget->clear();
    auto pList = server->ProductList();
    int l = server->CellsCount();
    for (int i = 0; i < l; i++)
    {
        if (pList[i] != NULL)
        {
            ui->listWidget->addItem(pList[i]->product->code);
        }
    }
    isCurrent = true;
}


void MainWindow::on_ReceivedButton_clicked()
{
    ui->listWidget->clear();

    auto rProducts = server->ReceivedProducts();
    for (auto p = rProducts.begin(); p != rProducts.end(); p++)
    {
        if (p->status == "Получено")
        {
            ui->listWidget->addItem(p->code);
        }
    }

    isCurrent = false;
    ui->deleteButton->setEnabled(false);
}


void MainWindow::on_RefusalButton_clicked()
{
    ui->listWidget->clear();

    auto rProducts = server->ReceivedProducts();
    for (auto p = rProducts.begin(); p != rProducts.end(); p++)
    {
        if (p->status != "Получено")
        {
            ui->listWidget->addItem(p->code);
        }
    }

    isCurrent = false;
    ui->deleteButton->setEnabled(false);
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (isCurrent)
    {
        ui->deleteButton->setEnabled(true);
        int cell = -1;
        auto pi = server->GetProductInfo(item->text(), cell);
        if (pi != NULL && pi->product != NULL)
        {
            ShowStaffInfo(*pi->product, pi->arrivalDate, pi->departureDate, "Ячейка " + QString::number(cell));
        }
        else
        {
            qDebug() << "STAFFINFO:" << cell;
        }
    }
    else
    {
        auto rd = server->GetReceived(item->text());
        auto pr = server->ReadProduct(item->text());
        if (rd != NULL && pr != NULL)
        {
            ShowStaffInfo(*pr, rd->arrivalDate, rd->receivingDate, rd->status);
        }
        else
        {
            qDebug() << "STAFFINFO!";
        }
    }
}

void MainWindow::ShowStaffInfo(Product& p, QDateTime d1, QDateTime d2, QString s)
{
    ui->nameStaff->setText(p.name);
    ui->priceStaff->setText(p.price);
    ui->descriptionStaff->setText(p.description);

    QPixmap img(p.link);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(img.scaled(w, h, Qt::KeepAspectRatio));

    ui->ArrivalDateLabel->setText( d1.toString( "dd.MM.yyyy hh:mm:ss" ) );
    ui->date2Label->setText( d2.toString( "dd.MM.yyyy hh:mm:ss" ) );;

    s = s.replace(", ", "\n");
    s = s.replace(": ", "\n");
    ui->cell->setText(s);
}

void MainWindow::on_deleteButton_clicked()
{
    auto item = ui->listWidget->currentItem();
    if (item != NULL)
    {
        int cell = -1;

        auto pi = server->GetProductInfo(item->text(), cell);
        if (pi != NULL)
        {
            server->SetReceived(cell, "Забрано на склад");
        }
        else
        {
            QMessageBox::critical(this, "Ошибка!", "Неправильно указан товар.");
        }
    }
    else
    {
        QMessageBox::critical(this, "Ошибка!", "Неправильно указан товар.");
    }
}


void MainWindow::on_addButton_clicked()
{
    pWin = new ProductWindow(this);
    pWin->setModal(true);
    pWin->exec();

    if (pWin->code != "")
    {
        Product* p = server->ReadProduct(pWin->code);
        if (p != NULL)
        {
            auto p1 = new ProductInfo(p,
                                      QDateTime::currentDateTime().toString(Qt::ISODate),
                                      QDateTime::currentDateTime().addDays(7).toString(Qt::ISODate));

            int cell = server->AddProductInfo(*p1);
            if (cell != -1)
            {
                QMessageBox::information(this, "", "Положите товар в " + QString::number(cell) + " ячейку.");
            }
            else
            {
                QMessageBox::critical(this, "Ошибка!", "Все ячейки заняты!");
            }
        }
        else
        {
            QMessageBox::critical(this, "Ошибка!", "Несуществующий товар! Пожалуйста, попробуйте ещё раз.");
        }
    }
}

void MainWindow::on_statsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    int max = 0;

    QVector<double> x(7), yr(7), ya(7), yc(7);
    for (int i = 1; i < 8; i++)
    {
        x[i-1] = i;
    }

    auto pList = server->ProductList();
    int l = server->CellsCount();
    for (int i = 0; i < l; i++)
    {
        if (pList[i] != NULL)
        {
            int day = 6 - pList[i]->arrivalDate.daysTo(QDateTime::currentDateTime());
            if (day >= 0 && day < 7)
            {
                ya[day]++;
                if (ya[day] > max)
                {
                    max = ya[day];
                }
            }
        }
    }

    auto rProducts = server->ReceivedProducts();
    for (auto p = rProducts.begin(); p != rProducts.end(); p++)
    {
        int aDays = 6 - p->arrivalDate.daysTo(QDateTime::currentDateTime());
        if (aDays >= 0 && aDays < 7)
        {
            ya[aDays]++;
            if (ya[aDays] > max)
            {
                max = ya[aDays];
            }
        }

        int rDays = 6 - p->receivingDate.daysTo(QDateTime::currentDateTime());
        if (rDays >= 0 && rDays < 7)
        {
            if (p->status == "Получено")
            {
                yr[rDays]++;
                if (yr[rDays] > max)
                {
                    max = yr[rDays];
                }
            }
            else
            {
                yc[rDays]++;
                if (yc[rDays] > max)
                {
                    max = yc[rDays];
                }
            }
        }
    }

    ui->widget->yAxis->setRange(0, max);
    ui->widget->xAxis->setRange(1, 7);

    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->addGraph();

    ui->widget->graph(0)->setPen(QPen(Qt::red));
    ui->widget->graph(1)->setPen(QPen(Qt::green));
    ui->widget->graph(2)->setPen(QPen(Qt::blue));

    ui->widget->graph(0)->setData(x, yc);
    ui->widget->graph(1)->setData(x, yr);
    ui->widget->graph(2)->setData(x, ya);

    ui->widget->replot();

    qDebug() << x << max;
    qDebug() << ya << yr << yc;
}


void MainWindow::on_backToStaffButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

