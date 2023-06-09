/********************************************************************************
** Form generated from reading UI file 'auth.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_H
#define UI_AUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Auth
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *loginInput;
    QLabel *label_2;
    QLineEdit *passwordInput;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Auth)
    {
        if (Auth->objectName().isEmpty())
            Auth->setObjectName(QString::fromUtf8("Auth"));
        Auth->resize(184, 97);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Auth->sizePolicy().hasHeightForWidth());
        Auth->setSizePolicy(sizePolicy);
        Auth->setMinimumSize(QSize(184, 97));
        Auth->setMaximumSize(QSize(184, 97));
        Auth->setModal(true);
        verticalLayout = new QVBoxLayout(Auth);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(Auth);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        loginInput = new QLineEdit(Auth);
        loginInput->setObjectName(QString::fromUtf8("loginInput"));

        formLayout->setWidget(0, QFormLayout::FieldRole, loginInput);

        label_2 = new QLabel(Auth);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        passwordInput = new QLineEdit(Auth);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordInput);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(Auth);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Auth);
        QObject::connect(buttonBox, SIGNAL(accepted()), Auth, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Auth, SLOT(reject()));

        QMetaObject::connectSlotsByName(Auth);
    } // setupUi

    void retranslateUi(QDialog *Auth)
    {
        Auth->setWindowTitle(QApplication::translate("Auth", "Authentication", nullptr));
        label->setText(QApplication::translate("Auth", "Login", nullptr));
        label_2->setText(QApplication::translate("Auth", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Auth: public Ui_Auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_H
