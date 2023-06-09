#ifndef PRODUCTWINDOW_H
#define PRODUCTWINDOW_H

#include <QDialog>

namespace Ui {
class ProductWindow;
}

class ProductWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProductWindow(QWidget *parent = nullptr);
    ~ProductWindow();

    QString code = "";

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ProductWindow *ui;
};

#endif // PRODUCTWINDOW_H
