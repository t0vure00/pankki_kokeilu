#ifndef RFIDINTERFACECLASS_H
#define RFIDINTERFACECLASS_H

#include "DLLRFID_global.h"
#include "engineclass.h"
#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QList>
#include <QByteArray>

class DLLRFID_EXPORT RFIDInterfaceClass : public QObject
{
    Q_OBJECT
public:
    RFIDInterfaceClass(QObject * parent = nullptr);

signals:
    void sendSignalToEngine();
    void sendSignalToExe(QString);
    //void sendSignalToEngineToCheckID(QString);

public slots:
    void receiveSignalFromExe();
    void receiveSignalFromEngine(QString);

private:
    EngineClass *engineClass;
    QSerialPort serialPort;

};

#endif // RFIDINTERFACECLASS_H
