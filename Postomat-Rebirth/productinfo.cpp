#include "productinfo.h"

ProductInfo::ProductInfo(Product* p, QString arrival, QString departure)
{
    product = p;
    arrivalDate = QDateTime::fromString(arrival, Qt::ISODate);
    departureDate = QDateTime::fromString(departure, Qt::ISODate);
}

QString ProductInfo::ToString()
{
    return product->code + " " + arrivalDate.toString(Qt::ISODate) + " " + departureDate.toString(Qt::ISODate);
}
