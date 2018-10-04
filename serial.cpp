#include "serial.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

Serial::Serial()
{
    setup(9600);
    serial->clear();
}

void Serial::setup(int baudRate)
{
    serial = new QSerialPort(this);
    serial->setPortName("/dev/ttyUSB0");
    if(serial->open(QIODevice::ReadWrite)){
        serial->setBaudRate(baudRate);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        qDebug()<<"device open";
    }else {
        qDebug() << serial->error();
    }

    /*if you send an inquiry from here, then the first time you will inquiry from a function
     * it will read the buffer without any problem*/
  //   serial->readAll();
}

void Serial::sendCommand(QByteArray value)
{
    serial->write(value);
}

void Serial::sendReadInquiry(QByteArray mes)
{
    serial->write(mes);

    QByteArray valueRead("",7);

    valueRead = serial->readAll();

    emit sendByteToInquiry(valueRead);
}
