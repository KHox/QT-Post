#ifndef AUTH_H
#define AUTH_H

#include <QDialog>

namespace Ui {
class Auth;
}



class Auth : public QDialog
{
    Q_OBJECT

public:
    explicit Auth(QWidget *parent = nullptr);
    ~Auth();

    bool isAccepted = false;
    QString login;
    QString password;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Auth *ui;
};

#endif // AUTH_H
