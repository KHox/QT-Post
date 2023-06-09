/********************************************************************************
** Form generated from reading UI file 'productwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTWINDOW_H
#define UI_PRODUCTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProductWindow
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ProductWindow)
    {
        if (ProductWindow->objectName().isEmpty())
            ProductWindow->setObjectName(QString::fromUtf8("ProductWindow"));
        ProductWindow->resize(198, 71);
        ProductWindow->setMinimumSize(QSize(198, 71));
        ProductWindow->setMaximumSize(QSize(198, 71));
        verticalLayout = new QVBoxLayout(ProductWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(ProductWindow);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(ProductWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(ProductWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ProductWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), ProductWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ProductWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(ProductWindow);
    } // setupUi

    void retranslateUi(QDialog *ProductWindow)
    {
        ProductWindow->setWindowTitle(QApplication::translate("ProductWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("ProductWindow", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\276\320\262\320\260\321\200\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductWindow: public Ui_ProductWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTWINDOW_H
