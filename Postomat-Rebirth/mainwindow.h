#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QTimer>
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QListWidgetItem>
#include <QVector>
#include "server.h"
#include "auth.h"
#include "productwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_userButton_clicked();

    void on_lineEdit_6_textEdited(const QString &arg1);

    void on_lineEdit_5_textEdited(const QString &arg1);

    void on_lineEdit_4_textEdited(const QString &arg1);

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_lineEdit_1_textEdited(const QString &arg1);

    QString GetCode();
    void StartFind(QString code);
    void ShowProductInfo();

    void on_receivingButton_clicked();

    void on_cancelButton_clicked();

    void on_confirmButton_clicked();

    void on_staffButton_clicked();

    void on_backButton_clicked();

    void on_currentButton_clicked();

    void on_ReceivedButton_clicked();

    void on_RefusalButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void ShowStaffInfo(Product& p, QDateTime d1, QDateTime d2, QString);

    void on_deleteButton_clicked();

    void on_addButton_clicked();

    void on_statsButton_clicked();

    void on_backToStaffButton_clicked();

private:
    Ui::MainWindow *ui;
    Auth* authWindow;
    ProductWindow* pWin;

    QMovie* gif;
    Server* server;

    int currentCell = -1;
    ProductInfo* pi;

    bool isCurrent = false;
};
#endif // MAINWINDOW_H
