#include "receiveddata.h"

ReceivedData::ReceivedData(QString str)
{
    auto s = str.split("___");
    code = s[0];
    status = s[1];
    arrivalDate = QDateTime::fromString(s[2], Qt::ISODate);
    receivingDate = QDateTime::fromString(s[3], Qt::ISODate);
}

ReceivedData::ReceivedData(QString code, QString status, QDateTime ar, QDateTime re)
{
    this->code = code;
    this->status = status;
    this->arrivalDate = ar;
    this->receivingDate = re;
}

QString ReceivedData::ToString()
{
    return code + "___" + status + "___" + arrivalDate.toString(Qt::ISODate) + "___" + receivingDate.toString(Qt::ISODate);
}
