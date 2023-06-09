#include "auth.h"
#include "ui_auth.h"

Auth::Auth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Auth)
{
    ui->setupUi(this);
}

Auth::~Auth()
{
    delete ui;
}

void Auth::on_buttonBox_accepted()
{
    isAccepted = true;
    login = ui->loginInput->text();
    password = ui->passwordInput->text();
}
