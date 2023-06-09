#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <QTextStream>


class Product
{
public:
    Product(QString code = "", QString name = "unknown",
            QString description = "unknown", QString price = "unknown")
    {
        this->code = code;
        this->name = name;
        this->description = description;
        this->price = price;
    };

    QString code;
    QString name;
    QString description;
    QString price;
    QString link;

    friend QTextStream& operator<<(QTextStream& out, const Product&);
    friend QString operator>>(QString in, Product&);
};

#endif
