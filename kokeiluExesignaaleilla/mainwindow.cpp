#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug() << "Ollaan Mainwindowin costructorissa";

    ui->setupUi(this);

    RFIDDLL = new RFIDInterfaceClass;

    connect(this, SIGNAL(sendSignalToRFIDDLL()),
            RFIDDLL,SLOT(receiveSignalFromExe()));

    connect(RFIDDLL, SIGNAL(sendSignalToExe(QString)),
            this,SLOT(receiveSignalFromRFIDDLL(QString)));

}

MainWindow::~MainWindow()
{
    qDebug() << "Ollaan Mainwindowin destructorissa";
    delete RFIDDLL;
    delete ui;
}

void MainWindow::receiveSignalFromRFIDDLL(QString b)
{
    qDebug() << "Ollaan Manwindowissa saatu signaali RFIDDLL:ltä " << b;
    ui->label->setText(b);

}


void MainWindow::on_Sulje_clicked()
{
    close();
}

void MainWindow::on_Start_clicked()
{
    //ui->Start->setEnabled(false);
    emit sendSignalToRFIDDLL();
}

void MainWindow::on_Clean_clicked()
{
    //ui->Start->setEnabled(true);
    ui->label->setText("");
}
