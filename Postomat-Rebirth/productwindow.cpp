#include "productwindow.h"
#include "ui_productwindow.h"

ProductWindow::ProductWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductWindow)
{
    ui->setupUi(this);
}

ProductWindow::~ProductWindow()
{
    delete ui;
}

void ProductWindow::on_buttonBox_accepted()
{
    code = ui->lineEdit->text();
}

