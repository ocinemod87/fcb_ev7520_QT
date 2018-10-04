#ifndef SERIALSENDRECEIVE_H
#define SERIALSENDRECEIVE_H
#include <QObject>
#include <QSerialPort>


class Serial: public QObject
{
    Q_OBJECT
public:
    Serial();

private:
    QSerialPort *serial;
    void setup(int baudRate = 9600);

private slots:
    void sendCommand(QByteArray value);
    void sendReadInquiry(QByteArray mes);

signals:
    void sendByteToInquiry(QByteArray);
};

#endif // SERIALSENDRECEIVE_H
