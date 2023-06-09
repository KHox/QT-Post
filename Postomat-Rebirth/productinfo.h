#ifndef PRODUCTINFO_H
#define PRODUCTINFO_H
#include <QString>
#include <QDateTime>
#include "product.h"


class ProductInfo
{
public:
    ProductInfo()
    {
        product = NULL;
        arrivalDate = QDateTime::currentDateTime();
        departureDate = QDateTime::currentDateTime();
    };
    ProductInfo(Product*, QString arrival, QString departure);

    QDateTime arrivalDate;
    QDateTime departureDate;
    Product* product;

    QString ToString();
};

#endif // PRODUCTINFO_H
