#ifndef ENGINECLASS_H
#define ENGINECLASS_H

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QList>
#include <QByteArray>

class EngineClass : public QObject
{
    Q_OBJECT
public:
    EngineClass(QObject * parent = nullptr);

signals:
    void sendSignalToInterface(QString);

public slots:
    void receiveSignalFromInterface();
    void readID();
    bool checkID(QString);

private:
    QSerialPort SerialPort;

};

#endif // ENGINECLASS_H
