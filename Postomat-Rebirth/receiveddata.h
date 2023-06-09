#ifndef RECEIVEDDATA_H
#define RECEIVEDDATA_H
#include <QString>
#include <QDateTime>
#include <QTextStream>

class ReceivedData
{
public:
    ReceivedData(QString);
    ReceivedData(QString code, QString status, QDateTime ar, QDateTime re);

    QString code;
    QDateTime arrivalDate;
    QDateTime receivingDate;
    QString status;

    QString ToString();
};

#endif // RECEIVEDDATA_H
