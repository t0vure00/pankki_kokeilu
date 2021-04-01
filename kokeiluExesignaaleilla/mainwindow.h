#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rfidinterfaceclass.h"
#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QString>
#include <QList>
#include <QByteArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    RFIDInterfaceClass *RFIDDLL;

signals:
    void sendSignalToRFIDDLL();

public slots:
    void receiveSignalFromRFIDDLL(QString);

private slots:
    void on_Sulje_clicked();
    void on_Start_clicked();
    void on_Clean_clicked();
};
#endif // MAINWINDOW_H
