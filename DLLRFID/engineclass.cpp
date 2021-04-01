#include "engineclass.h"

EngineClass::EngineClass(QObject * parent):QObject(parent)
{
    qDebug() << "Ollaan RFIDDLL enginen constructorissa";


}

void EngineClass::receiveSignalFromInterface()
{


    QString muuttuja = "Aasi";
    qDebug() << "Ollaan saatu signaali interfacelta aloittaa";

    SerialPort.setPortName("COM5");
    qDebug() << SerialPort.portName();
    SerialPort.setBaudRate(9600);
    SerialPort.setDataBits(QSerialPort::Data8);
    SerialPort.setParity(QSerialPort::NoParity);
    SerialPort.setStopBits(QSerialPort::OneStop);
    SerialPort.setFlowControl(QSerialPort::HardwareControl);

    if(!SerialPort.open(QIODevice::ReadWrite)){
        qDebug() << "ei aukea" << Qt::endl;
    }else{
        qDebug() << "portti aukesi" << Qt::endl;
        connect(&SerialPort,SIGNAL(readyRead()),
                this,SLOT(readID()));
        //QByteArray readData = SerialPort.readAll();
        /*while (SerialPort.waitForReadyRead()){
            qDebug() << "Ollaan whilessa";
            //muuttuja = readData.append(SerialPort.readAll());
            qDebug() << muuttuja;
            qDebug() << "Data luettu, lähetetään signaali ja suljetaan portti";
            //this->close();*/
        }

    //}
    //SerialPort.close();
    qDebug() << "Lähdetään enginestä takaisin interfaceen";
    //emit sendSignalToInterface(muuttuja);
}

void EngineClass::readID()
{
    qDebug() << "Ollaan readID";
    QByteArray readData = SerialPort.readAll();
    QString muuttuja = readData.append(SerialPort.readAll());
    qDebug() << muuttuja;
    muuttuja.remove("-");
    muuttuja.remove(">");
    muuttuja.remove("\r\n");
    //SerialPort.close();
    //this->checkID(muuttuja);
    if(this->checkID(muuttuja) == true){
        qDebug() << "Ollaan readID takaisin ja oli true";
        emit sendSignalToInterface(muuttuja);
    }else{
        qDebug() << "Ollaan readID takaisin ja oli false";
        receiveSignalFromInterface();
    }
    //emit sendSignalToInterface(muuttuja);

}

bool EngineClass::checkID(QString a)
{
    qDebug("Ollaan Enginen checkID");
    if(a == "06000DA7C7"){
        qDebug("Ollaan true");
        return true;
    }else{
        qDebug("Oli false");
        return false;
    }
    qDebug("Oli false");
    return false;
}
