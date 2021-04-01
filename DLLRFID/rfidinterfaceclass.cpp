#include "rfidinterfaceclass.h"

RFIDInterfaceClass::RFIDInterfaceClass(QObject * parent):QObject(parent)
{
    qDebug() << "Ollaan RFIDDLL interfacen constructorissa";

    engineClass = new EngineClass;

    connect(this, SIGNAL(sendSignalToEngine()),
            engineClass,SLOT(receiveSignalFromInterface()));

    connect(engineClass, SIGNAL(sendSignalToInterface(QString)),
            this,SLOT(receiveSignalFromEngine(QString)));

    /*connect(this, SIGNAL(sendSignalToEngineToCheckID(QString)),
            this,SLOT(receiveSignalFromEngine(QString)));
    connect(&serialPort, SIGNAL(readyRead()),
            this, SLOT(receiveSignalFromInterface()));*/
}

void RFIDInterfaceClass::receiveSignalFromExe()
{
    qDebug() << "Ollaan saatu signaali Exe:ltä aloittaa";
    //emit serialPort.readyRead();
    emit sendSignalToEngine();
}

void RFIDInterfaceClass::receiveSignalFromEngine(QString a)
{
    qDebug() << "Ollaan saatu signaali engineltä mennä takaisin Exeen";
    //emit serialPort.readyRead();
    //emit
    emit sendSignalToExe(a);
}
