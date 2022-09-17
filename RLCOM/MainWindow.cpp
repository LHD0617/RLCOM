/*
 * Copyright (C), 1988-1999, Xxxxxx Tech. Co., Ltd.
 * FileName: MainWindow.h
 * Description: 主窗口头文件
 * Change Logs:
  |Date          |Author       |Notes     			|version
  |2022-09-17    |满心欢喜     |Initial build     	|1.0.0
 */

/*  @include  */
#include "MainWindow.h"
#include "ui_MainWindow.h"


/**
    * @name		MainWindow
    * @brief  	构造函数
  */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(uint8_t i = 0; i < MAX_BAUDLIST; i++)
    {
        ui->BaudCbox->addItem(BaudList[i]);
    }
    ui->BaudCbox->setCurrentIndex(4);

    for(uint8_t i = 0; i < 4; i++)
    {
        ui->DataBitCbox->addItem(DataBitList[i]);
    }
    ui->DataBitCbox->setCurrentIndex(3);

    for(uint8_t i = 0; i < 3; i++)
    {
        ui->CheckBitCbox->addItem(CheckBitList[i]);
    }

    for(uint8_t i = 0; i < 3; i++)
    {
        ui->StopBitCbox->addItem(StopBitList[i]);
    }
    connect(ui->SwitchPortPbtn, SIGNAL(clicked()), this, SLOT(SwitchPort()));

    connect(&RefreshPortTimer, SIGNAL(timeout()), this, SLOT(RefreshPort()));

    RefreshPortTimer.start(100);
}

/**
    * @name		~MainWindow
    * @brief  	关闭函数
  */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
    * @name		RefreshPort
    * @brief  	刷新串口列表
  */
void MainWindow::RefreshPort()
{
    if(!SwitchPortFlag)
    {
        QStringList TempPortList;
        foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
        {
            TempPortList << info.portName();
        }
        if(TempPortList != PortList)
        {
            PortList.clear();

            PortList = TempPortList;

            ui->PortCbox->clear();

            ui->PortCbox->addItems(PortList);
        }
    }
    else
    {
        QStringList TempPortList;
        foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
        {
            TempPortList << info.portName();
        }
        if(!TempPortList.contains(ui->PortCbox->currentText()))
        {
            SwitchPort();
        }
    }
}

/**
    * @name		SwitchPort
    * @brief  	串口开关函数
  */
void MainWindow::SwitchPort()
{
    if(!SwitchPortFlag)
    {
        if(ui->PortCbox->count() > 0)
        {
            Ser.setPortName(ui->PortCbox->currentText());

            Ser.setBaudRate(ui->BaudCbox->currentText().toInt());

            Ser.setDataBits((QSerialPort::DataBits)ui->DataBitCbox->currentText().toInt());

            uint8_t CheckBit = ui->CheckBitCbox->currentIndex();

            if(!CheckBit)
            {
                Ser.setParity((QSerialPort::NoParity));
            }
            else
            {
                Ser.setParity((QSerialPort::Parity)(CheckBit + 1));
            }
            Ser.setStopBits((QSerialPort::StopBits)ui->StopBitCbox->currentIndex());

            if(Ser.open(QIODevice::ReadWrite))
            {
                ShowMessage(ui->PortCbox->currentText() + "打开成功");

                SwitchPortFlag = true;

                ui->SwitchPortPbtn->setText("关闭串口");

                ui->PortCbox->setEnabled(false);

                ui->BaudCbox->setEnabled(false);

                ui->DataBitCbox->setEnabled(false);

                ui->CheckBitCbox->setEnabled(false);

                ui->StopBitCbox->setEnabled(false);

                Ser.clear();
            }
            else
            {
                ShowMessage(ui->PortCbox->currentText() + "打开失败");
            }
        }
        else
        {
            ShowMessage("未搜索到可用串口");
        }
    }
    else
    {
        SwitchPortFlag = false;

        ui->SwitchPortPbtn->setText("打开串口");

        ui->PortCbox->setEnabled(true);

        ui->BaudCbox->setEnabled(true);

        ui->DataBitCbox->setEnabled(true);

        ui->CheckBitCbox->setEnabled(true);

        ui->StopBitCbox->setEnabled(true);

        Ser.close();

        ShowMessage(ui->PortCbox->currentText() + "已关闭");
    }
}

/**
    * @name		ShowMessage
    * @brief  	显示消息函数
  */
void MainWindow::ShowMessage(QString Message)
{
    ui->statusbar->showMessage(Message, 1500);
}
