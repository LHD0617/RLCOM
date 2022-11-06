/*
 * Copyright (C), 1988-1999, Xxxxxx Tech. Co., Ltd.
 * FileName: MainWindow.cpp
 * Description: 主窗口
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

    TimeLab = new QLabel();
    DataLab = new QLabel();
    MousePostLab = new QLabel(ui->ImageLab);

    MousePostLab->setStyleSheet("color:red;");
    ui->ImageLab->setMouseTracking(true);
    ui->statusbar->addPermanentWidget(DataLab);
    ui->statusbar->addPermanentWidget(TimeLab);

    UpdateTime();

    ui->BaudCbox->setCurrentIndex(4);
    ui->DataBitCbox->setCurrentIndex(3);
    ui->HeightLedit->setValidator(new QIntValidator(0, 999, this));
    ui->WidthLedit->setValidator(new QIntValidator(0, 999, this));
    ui->ChartWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ReadConfigure();

    connect(ui->SwitchPortPbtn, SIGNAL(clicked()), this, SLOT(SwitchPort()));
    connect(ui->CleanReceivePbtn, SIGNAL(clicked()), this, SLOT(CleanReceiveData()));
    connect(ui->CleanStatsPbtn, SIGNAL(clicked()), this, SLOT(CleanStats()));
    connect(ui->CleanSendPbtn, SIGNAL(clicked()), this, SLOT(CleanSendData()));
    connect(ui->SendPbtn, SIGNAL(clicked()), this, SLOT(SendData()));
    connect(ui->SwitchImagePbtn, SIGNAL(clicked()), this, SLOT(SwitchImage()));
    connect(ui->SwitchWaveformPbtn, SIGNAL(clicked()), this, SLOT(SwitchChart()));
    connect(ui->XaxisZoomPbtn, SIGNAL(clicked()), this, SLOT(XAxisZoom()));
    connect(ui->XaxisShrinkPbtn, SIGNAL(clicked()), this, SLOT(XAxisShrink()));
    connect(ui->TimeSendCbox, SIGNAL(stateChanged(int)), this, SLOT(AutoSend(int)));
    connect(&Ser, SIGNAL(readyRead()), this, SLOT(ReceiveData()));
    connect(&AutoSendTimer, SIGNAL(timeout()), this, SLOT(SendData()));
    connect(&RefreshPortTimer, SIGNAL(timeout()), this, SLOT(RefreshPort()));
    connect(&UpdateTimeTimer, SIGNAL(timeout()), this, SLOT(UpdateTime()));

    ui->SendTextEdit->installEventFilter(this);
    ui->ImageLab->installEventFilter(this);

    UpdateTimeTimer.start(1000);
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
    WriteConfigure();

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
    * @name		CleanReceiveData
    * @brief  	清空接收数据函数
  */
void MainWindow::CleanReceiveData()
{
    ui->ReceiveTextEdit->clear();
}

/**
    * @name		CleanStats
    * @brief  	清空接收统计函数
  */
void MainWindow::CleanStats()
{
    ReceiveCount = 0;
    ReceiveLastCount = 0;
    ReceiveSpeed = 0;
    SendCount = 0;
    DataLab->setText(QString("共接收%1字节，速度%2字节/秒   共发送%3字节")
                    .arg(ReceiveCount, 10)
                    .arg(ReceiveSpeed, 10)
                    .arg(SendCount, 10));
}

/**
    * @name		CleanSendData
    * @brief  	清空发送数据函数
  */
void MainWindow::CleanSendData()
{
    ui->SendTextEdit->clear();
}

/**
    * @name		SwitchImage
    * @brief  	开关图像传输
  */
void MainWindow::SwitchImage()
{
    if(!SwitchImageFlag)
    {
        if(SwitchPortFlag)
        {
            Height = ui->HeightLedit->text().toInt();
            Width = ui->WidthLedit->text().toInt();
            if(Height && Width)
            {
                if(ui->ImageModeCBox->currentIndex() == 0)
                {
                    ImageDataSize = Height * Width;
                }
                else
                {
                    if((Height * Width) % 8 == 0)
                        ImageDataSize = (Height * Width) / 8;
                    else
                        ImageDataSize = (Height * Width) / 8 + 1;
                }
                ImageData.resize(Height * Width * PIXEL_SIZE * PIXEL_SIZE);
                ui->SwitchImagePbtn->setText("停止接收");
                ui->ImageModeCBox->setEnabled(false);
                ui->HeightLedit->setEnabled(false);
                ui->WidthLedit->setEnabled(false);
                SwitchImageFlag = true;
            }
            else
            {
                ShowMessage("请输入正确的图像尺寸");
            }
        }
        else
        {
            ShowMessage("请先打开串口");
        }
    }
    else
    {
        ImageHeadFlag = false;
        ShowImageFlag = false;
        ui->ImageLab->setText("Waiting......");
        ui->SwitchImagePbtn->setText("开始接收");
        ui->ImageModeCBox->setEnabled(true);
        ui->HeightLedit->setEnabled(true);
        ui->WidthLedit->setEnabled(true);
        SwitchImageFlag = false;
    }
}

/**
    * @name		SwitchChart
    * @brief  	开关波形传输
  */
void MainWindow::SwitchChart()
{
    if(!SwitchChartFlag)
    {
        if(SwitchPortFlag)
        {
            Channle = ui->ChannleSbox->text().toInt();
            DataType = ui->DataTypeCbox->currentIndex();
            if(DataType > 5)
            {
                ChartDataSize = (DataType - 5) * 4 * Channle;
            }
            else
            {
                ChartDataSize = ((DataType % 3) + 1) * Channle;
            }
            QHBoxLayout* Layout = new QHBoxLayout();
            QWidget* ChartLabWidget = new QWidget();
            for(uint8_t i = 0; i < Channle; i++)
            {
                ui->ChartWidget->addGraph();
                ChartLabel[i] = new UnitChartLabel(ChartGraphColor[i]);
                Layout->addWidget(ChartLabel[i]);
                ui->ChartWidget->graph(i)->setPen(QPen(ChartGraphColor[i]));
            }
            ChartLabWidget->setLayout(Layout);
            ui->gridLayout_6->addWidget(ChartLabWidget, 1, 0, 1, 4);
            ui->ChartWidget->replot();
            ui->SwitchWaveformPbtn->setText("停止接收");
            ui->ChannleSbox->setEnabled(false);
            ui->DataTypeCbox->setEnabled(false);
            SwitchChartFlag = true;
        }
        else
        {
            ShowMessage("请先打开串口");
        }
    }
    else
    {
        ChartHeadFlag = false;
        ChartCount = 0;
        ui->ChartWidget->clearGraphs();
        ui->ChartWidget->replot();
        auto ChartLabWidget = ui->gridLayout_6->itemAtPosition(1, 0);
        ChartLabWidget->widget()->setVisible(false);
        ui->gridLayout_6->removeWidget(ChartLabWidget->widget());
        ui->SwitchWaveformPbtn->setText("开始接收");
        ui->ChannleSbox->setEnabled(true);
        ui->DataTypeCbox->setEnabled(true);
        SwitchChartFlag = false;
    }
}

/**
    * @name		ReceiveData
    * @brief  	接收数据函数
  */
void MainWindow::ReceiveData()
{
    QByteArray Data = Ser.readAll();
    /* 串口收发 */
    if(ui->TabWidget->currentIndex() == 0)
    {
        if(ui->TalkWindowCbox->isChecked())
        {
            ui->ReceiveTextEdit->append("<font color=\"#FF0020\">" + NowTime + " Receive:" + "</font>");
        }

        if(!ui->HexShowCbox->isChecked())
        {
            ui->ReceiveTextEdit->append(Data);
        }
        else
        {
            ui->ReceiveTextEdit->append(ByteArrayToHexString(Data));
        }
        if(ui->AutoFollowCbox->isChecked())
        {
            ui->ReceiveTextEdit->moveCursor(QTextCursor::End);
        }
    }
    /* 图像传输 */
    if(ui->TabWidget->currentIndex() == 1)
    {
        if(SwitchImageFlag)
        {
            if(!ImageHeadFlag)
            {
                for(int i = 0; i < Data.size(); i++)
                {
                    if((uint8_t)Data[i] != ImageHeadData[ImageHeadLen])
                    {
                        ImageHeadLen = 0;
                    }
                    if((uint8_t)Data[i] == ImageHeadData[ImageHeadLen])
                    {
                        ImageHeadLen++;
                    }
                    else
                    {
                        ImageHeadLen = 0;
                    }
                    if(ImageHeadLen == 4)
                    {
                        ImageHeadFlag = true;
                        ImageHeadLen = 0;
                        UartData.append(Data.mid(i + 1));
                        break;
                    }
                }
            }
            else
            {
                UartData.append(Data);

                if(UartData.size() >= (int)ImageDataSize)
                {
                    ui->ImageLab->setPixmap(QPixmap::fromImage(MakeImage()));
                    ImageHeadFlag = false;
                    ShowImageFlag = true;
                }
            }
        }
    }
    /* 虚拟示波 */
    if(ui->TabWidget->currentIndex() == 2)
    {
        if(SwitchChartFlag)
        {
            if(!ChartHeadFlag)
            {
                for(int i = 0; i < Data.size(); i++)
                {
                    if((uint8_t)Data[i] != ChartHeadData[ChartHeadLen])
                    {
                        ChartHeadLen = 0;
                    }
                    if((uint8_t)Data[i] == ChartHeadData[ChartHeadLen])
                    {
                        ChartHeadLen++;
                    }
                    else
                    {
                        ChartHeadLen = 0;
                    }
                    if(ChartHeadLen == 4)
                    {
                        ChartHeadFlag = true;
                        ChartHeadLen = 0;
                        UartData.append(Data.mid(i + 1));
                        break;
                    }
                }
            }
            else
            {
                UartData.append(Data);

                if(UartData.size() >= (int)ChartDataSize)
                {
                    double dat;

                    uint8_t UnitChannleSize = ChartDataSize / Channle;

                    for(uint8_t i = 0; i < Channle; i++)
                    {
                        switch(ui->DataTypeCbox->currentIndex())
                        {
                        case 0:
                            dat = *((uint8_t*)(UartData.data() + i * UnitChannleSize));
                        break;
                        case 1:
                            dat = *((uint16_t*)(UartData.data() + i * UnitChannleSize));
                        break;
                        case 2:
                            dat = *((uint32_t*)(UartData.data() + i * UnitChannleSize));
                        break;
                        case 3:
                            dat = *((int8_t*)(UartData.data() + i * UnitChannleSize));
                        break;
                        case 4:
                            dat = *((int16_t*)(UartData.data() + i * UnitChannleSize));
                        break;
                        case 5:
                            dat = *((int32_t*)(UartData.data() + i * UnitChannleSize));
                        break;
                        case 6:
                            dat = *((float*)(UartData.data() + i * UnitChannleSize));
                        break;
                        case 7:
                            dat = *((double*)(UartData.data() + i * UnitChannleSize));
                        break;
                        }
                        ui->ChartWidget->graph(i)->addData(ChartCount, dat);
                        ChartLabel[i]->Label->setText(QString("%1").arg(dat));
                        if(ui->AdaptiveCbox->isChecked())
                        {
                            ui->ChartWidget->graph(i)->rescaleValueAxis(true);
                        }
                        ui->ChartWidget->graph(i)->setVisible(ChartLabel[i]->CheckBox->isChecked());
                    }
                    uint32_t temp = ui->ChartWidget->graph(0)->dataCount();

                    if(ui->ChartAutoFollowCbox->isChecked())
                    {
                        ui->ChartWidget->xAxis->setRange(temp > ChartXRange ? temp - ChartXRange : 0, ChartXRange > temp ? ChartXRange : temp);
                    }
                    ui->ChartWidget->replot(QCustomPlot::rpQueuedReplot);
                    ChartCount++;
                    UartData.clear();
                    ChartHeadFlag = false;
                }
            }
        }
    }
    ReceiveCount += Data.size();
}

/**
    * @name		SendData
    * @brief  	发送数据函数
  */
void MainWindow::SendData()
{
    if(ui->TabWidget->currentIndex() == 0)
    {
        if(SwitchPortFlag)
        {
            QString Data = ui->SendTextEdit->toPlainText();

            if(Data.size() > 0)
            {
                if(ui->TalkWindowCbox->isChecked())
                {
                    ui->ReceiveTextEdit->append("<font color=\"#00DD00\">" + NowTime + " Send:" + "</font>");
                    ui->ReceiveTextEdit->append(Data);
                }

                if(ui->HexSendCbox->isChecked())
                {
                    if (Data.contains(" "))
                    {
                        Data.replace(QString(" "),QString(""));
                    }
                    QByteArray TempData = HexStringToQByteArray(Data);
                    Ser.write(TempData);
                    SendCount += TempData.size();
                }
                else
                {
                    if(ui->AutoEnterCBox->isChecked())
                    {
                        Data.append("\r\n");
                    }
                    Ser.write(Data.toUtf8());
                    SendCount += Data.size();
                }
                if(ui->SendCleanCbox->isChecked())
                {
                    CleanSendData();
                }
            }
            else
            {
                ShowMessage("请先输入数据");
            }
        }
        else
        {
            ShowMessage("请先打开串口");
        }
    }
}

/**
    * @name		AutoSend
    * @brief  	定时发送
  */
void MainWindow::AutoSend(int state)
{
    if(state)
    {
        ui->TimeSBox->setReadOnly(true);
        uint16_t time = ui->TimeSBox->value();
        AutoSendTimer.start(time);
    }
    else
    {
        AutoSendTimer.stop();
        ui->TimeSBox->setReadOnly(false);
    }
}

/**
    * @name		WriteConfigure
    * @brief  	写入配置文件函数
  */
void MainWindow::WriteConfigure()
{
    FILE *fp = fopen(ConfigureFileName, "w");
    fprintf(fp, "[Configure]\n");
    fprintf(fp, QString("[Baud]=%1\n").arg(ui->BaudCbox->currentIndex()).toLatin1());
    fprintf(fp, QString("[DataBit]=%1\n").arg(ui->DataBitCbox->currentIndex()).toLatin1());
    fprintf(fp, QString("[CheckBit]=%1\n").arg(ui->CheckBitCbox->currentIndex()).toLatin1());
    fprintf(fp, QString("[StopBit]=%1\n").arg(ui->StopBitCbox->currentIndex()).toLatin1());
    fprintf(fp, QString("[ImageMode]=%1\n").arg(ui->ImageModeCBox->currentIndex()).toLatin1());
    fprintf(fp, QString("[Channle]=%1\n").arg(ui->ChannleSbox->text()).toLatin1());
    fprintf(fp, QString("[DataType]=%1\n").arg(ui->DataTypeCbox->currentIndex()).toLatin1());
    fprintf(fp, QString("[Height]=%1\n").arg(ui->HeightLedit->text().toInt()).toLatin1());
    fprintf(fp, QString("[Width]=%1\n").arg(ui->WidthLedit->text().toInt()).toLatin1());

    if(ui->HexShowCbox->isChecked())
        fprintf(fp, "[HexShow]=true\n");
    else
        fprintf(fp, "[HexShow]=false\n");
    if(ui->AutoFollowCbox->isChecked())
        fprintf(fp, "[AutoFollow]=true\n");
    else
        fprintf(fp, "[AutoFollow]=false\n");
    if(ui->TalkWindowCbox->isChecked())
        fprintf(fp, "[TalkWindow]=true\n");
    else
        fprintf(fp, "[TalkWindow]=false\n");
    if(ui->HexSendCbox->isChecked())
        fprintf(fp, "[HexSend]=true\n");
    else
        fprintf(fp, "[HexSend]=false\n");
    if(ui->EnterSendCBox->isChecked())
        fprintf(fp, "[EnterSend]=true\n");
    else
        fprintf(fp, "[EnterSend]=false\n");
    if(ui->AutoEnterCBox->isChecked())
        fprintf(fp, "[AutoEnter]=true\n");
    else
        fprintf(fp, "[AutoEnter]=false\n");
    if(ui->SendCleanCbox->isChecked())
        fprintf(fp, "[SendClean]=true\n");
    else
        fprintf(fp, "[SendClean]=false\n");
    if(ui->GridCbox->isChecked())
        fprintf(fp, "[ImageGrid]=true\n");
    else
        fprintf(fp, "[ImageGrid]=false\n");
    if(ui->AdaptiveCbox->isChecked())
        fprintf(fp, "[Adaptive]=true\n");
    else
        fprintf(fp, "[Adaptive]=false\n");
    if(ui->ChartAutoFollowCbox->isChecked())
        fprintf(fp, "[AutoFollow]=true\n");
    else
        fprintf(fp, "[AutoFollow]=false\n");
    fclose(fp);
}

/**
    * @name		ReadConfigure
    * @brief  	读取配置文件函数
  */
void MainWindow::ReadConfigure()
{
    if(QFile(ConfigureFileName).exists())
    {
        FILE *fp = fopen(ConfigureFileName, "r");

        if(strcmp(ReadLineChars(fp, 0).toLatin1(), "[Configure]") == 0)
        {
            ui->BaudCbox->setCurrentIndex(ReadLineChars(fp, 1).split("=")[1].toInt());
            ui->DataBitCbox->setCurrentIndex(ReadLineChars(fp, 2).split("=")[1].toInt());
            ui->CheckBitCbox->setCurrentIndex(ReadLineChars(fp, 3).split("=")[1].toInt());
            ui->StopBitCbox->setCurrentIndex(ReadLineChars(fp, 4).split("=")[1].toInt());
            ui->ImageModeCBox->setCurrentIndex(ReadLineChars(fp, 5).split("=")[1].toInt());
            ui->ChannleSbox->setValue(ReadLineChars(fp, 6).split("=")[1].toInt());
            ui->DataTypeCbox->setCurrentIndex(ReadLineChars(fp, 7).split("=")[1].toInt());
            ui->HeightLedit->setText(ReadLineChars(fp, 8).split("=")[1]);
            ui->WidthLedit->setText(ReadLineChars(fp, 9).split("=")[1]);
            if(ReadLineChars(fp, 10).split("=")[1].toLatin1() == "true")
                ui->HexShowCbox->setChecked(true);
            else
                ui->HexShowCbox->setChecked(false);
            if(ReadLineChars(fp, 11).split("=")[1].toLatin1() == "true")
                ui->AutoFollowCbox->setChecked(true);
            else
                ui->AutoFollowCbox->setChecked(false);
            if(ReadLineChars(fp, 12).split("=")[1].toLatin1() == "true")
                ui->TalkWindowCbox->setChecked(true);
            else
                ui->TalkWindowCbox->setChecked(false);
            if(ReadLineChars(fp, 13).split("=")[1].toLatin1() == "true")
                ui->HexSendCbox->setChecked(true);
            else
                ui->HexSendCbox->setChecked(false);
            if(ReadLineChars(fp, 14).split("=")[1].toLatin1() == "true")
                ui->EnterSendCBox->setChecked(true);
            else
                ui->EnterSendCBox->setChecked(false);
            if(ReadLineChars(fp, 15).split("=")[1].toLatin1() == "true")
                ui->AutoEnterCBox->setChecked(true);
            else
                ui->AutoEnterCBox->setChecked(false);
            if(ReadLineChars(fp, 16).split("=")[1].toLatin1() == "true")
                ui->SendCleanCbox->setChecked(true);
            else
                ui->SendCleanCbox->setChecked(false);
            if(ReadLineChars(fp, 17).split("=")[1].toLatin1() == "true")
                ui->GridCbox->setChecked(true);
            else
                ui->GridCbox->setChecked(false);
            if(ReadLineChars(fp, 18).split("=")[1].toLatin1() == "true")
                ui->AdaptiveCbox->setChecked(true);
            else
                ui->AdaptiveCbox->setChecked(false);
            if(ReadLineChars(fp, 19).split("=")[1].toLatin1() == "true")
                ui->ChartAutoFollowCbox->setChecked(true);
            else
                ui->ChartAutoFollowCbox->setChecked(false);
        }
    }
}

/**
    * @name		MakeImage
    * @brief  	生成图像函数
  */
QImage MainWindow::MakeImage()
{
    uint8_t* DataBuffFp;
    uint8_t* ImageFp;
    uint8_t* PixelBaseFp;
    uint8_t PixelBit;
    uint16_t i, j, k, l;
    DataBuffFp = (uint8_t*)UartData.data();
    ImageFp = (uint8_t*)ImageData.data();

    /* 灰度图 */
    if(ui->ImageModeCBox->currentIndex() == 0)
    {
        for(i = 0; i < Height; i++)
        {
            for(j = 0; j < Width; j++)
            {
                PixelBit = *(DataBuffFp + i * Width + j);
                PixelBaseFp = ImageFp + i * Width * PIXEL_SIZE * PIXEL_SIZE + j * PIXEL_SIZE;
                for(k = 0; k < PIXEL_SIZE; k++)
                {
                    for(l = 0; l < PIXEL_SIZE; l++)
                    {
                        *(PixelBaseFp + k * Width * PIXEL_SIZE + l) = PixelBit;
                    }
                }
            }
        }
    }
    /* 二值化图 */
    else
    {
        for(i = 0; i < Height; i++)
        {
            for(j = 0; j < Width; j++)
            {
                if((*(DataBuffFp + (i * Width + j) / 8)) & (0x80 >> ((i * Width + j) % 8)))
                    PixelBit = 255;
                else
                    PixelBit = 0;
                PixelBaseFp = ImageFp + i * Width * PIXEL_SIZE * PIXEL_SIZE + j * PIXEL_SIZE;
                for(k = 0; k < PIXEL_SIZE; k++)
                {
                    for(l = 0; l < PIXEL_SIZE; l++)
                    {
                        *(PixelBaseFp + k * Width * PIXEL_SIZE + l) = PixelBit;
                    }
                }
            }
        }
    }
    if(ui->GridCbox->isChecked())
    {
        for(i = 0; i < Height; i++)
        {
            for(j = 0; j < Width * PIXEL_SIZE; j++)
            {
                *(ImageFp + i * Width * PIXEL_SIZE * PIXEL_SIZE + j) = 100;
            }
        }
        for(i = 0; i < Width; i++)
        {
            for(j = 0; j < Height * PIXEL_SIZE; j++)
            {
                *(ImageFp + i * PIXEL_SIZE + j * Width * PIXEL_SIZE) = 100;
            }
        }
    }
    UartData.clear();
    return QImage((const unsigned char *)ImageData.data(), Width * PIXEL_SIZE, Height * PIXEL_SIZE, Width * PIXEL_SIZE, QImage::Format_Grayscale8);
}

/**
    * @name		XAxisShrink
    * @brief  	X轴缩小
  */
void MainWindow::XAxisShrink()
{
    if(ChartXRange + 50 <= MAX_X_AXIS)
    {
        ChartXRange += 50;
    }
}

/**
    * @name		XAxisShrink
    * @brief  	X轴放大
  */
void MainWindow::XAxisZoom()
{
    if(ChartXRange - 50 >= MIN_X_AXIS)
    {
        ChartXRange -= 50;
    }
}

/**
    * @name		eventFilter
    * @brief  	事件过滤器
  */
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->SendTextEdit)
    {
        if(event->type() == QEvent::KeyPress)
        {
            if(ui->TabWidget->currentIndex() == 0)
            {
                QKeyEvent *k = static_cast<QKeyEvent *>(event);

                if(k->key() == Qt::Key_Return || k->key() == Qt::Key_Enter)
                {
                    if(ui->EnterSendCBox->isChecked())
                    {
                        SendData();
                    }
                    return true;
                }
            }
        }
    }
    if (obj == ui->ImageLab)
    {
        if(event->type() == QEvent::MouseMove)
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if(ShowImageFlag)
            {
                MousePostLab->setVisible(true);
                float RatioW = (float)Width / ui->ImageLab->width();
                float RatioH = (float)Height / ui->ImageLab->height();
                uint16_t MouseX = mouseEvent->localPos().x();
                uint16_t MouseY = mouseEvent->localPos().y();
                uint16_t MousePosX = MouseX * RatioW;
                uint16_t MousePosY = MouseY * RatioH;
                int16_t ShowLabPosX = 30;
                int16_t ShowLabPosY = 30;
                if(Width - MousePosX < 10)
                    ShowLabPosX = -50;
                if(Height - MousePosY < 5)
                    ShowLabPosY = -20;

                MousePostLab->move((MouseX + ShowLabPosX), (MouseY + ShowLabPosY));
                MousePostLab->setText(QString("(%1,%2)").arg(MousePosX).arg(MousePosY));
                MousePostLab->adjustSize();
            }
            else
                MousePostLab->setVisible(false);
        }
        if(event->type() == QEvent::Leave)
        {
            MousePostLab->setVisible(false);
        }
    }
    return false;
}

/**
    * @name		UpdateTime
    * @brief  	更新时间函数
  */
void MainWindow::UpdateTime()
{
    time_t nowtime;
    struct tm* p;
    time(&nowtime);
    p = localtime(&nowtime);
    NowTime = QString("%1:%2:%3").arg(p->tm_hour, 2, 10, QLatin1Char('0'))
            .arg(p->tm_min, 2, 10, QLatin1Char('0'))
            .arg(p->tm_sec, 2, 10, QLatin1Char('0'));
    TimeLab->setText("当前时间：" + NowTime);
    ReceiveSpeed = ReceiveCount - ReceiveLastCount;
    ReceiveLastCount = ReceiveCount;
    DataLab->setText(QString("共接收%1字节，速度%2字节/秒   共发送%3字节")
                    .arg(ReceiveCount, 10)
                    .arg(ReceiveSpeed, 10)
                    .arg(SendCount, 10));
}

/**
    * @name		ShowMessage
    * @brief  	显示消息函数
  */
void MainWindow::ShowMessage(QString Message)
{
    ui->statusbar->showMessage(Message, 1500);
}

/**
    * @name		ByteArrayToHexString
    * @brief  	QByteArray转QString
  */
QString ByteArrayToHexString(QByteArray ascii)
{
    QString ret;
    for(int i = 0; i < ascii.count(); i++)
    {
        ret.append(QString("%1 ").arg((uchar)ascii.at(i), 2, 16, (QChar)'0'));
    }
    return ret.toUpper();
}

/**
    * @name		HexStringToQByteArray
    * @brief  	Hex字符串转QByteArray
  */
QByteArray HexStringToQByteArray(QString str)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    QByteArray byteData;
    byteData.resize(len/2);
    char lstr,hstr;
    for(int i = 0; i < len; i++)
    {
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertCharToHex(hstr);
        lowhexdata = ConvertCharToHex(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = (hexdata << 4) + lowhexdata;
        byteData[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    byteData.resize(hexdatalen);
    return byteData;
}

/**
    * @name		ConvertCharToHex
    * @brief  	char 转为 16进制
  */
char ConvertCharToHex(char ch)
{
    /*
        0x30等于十进制的48，48也是0的ASCII值，，
        1-9的ASCII值是49-57，，所以某一个值－0x30，，
        就是将字符0-9转换为0-9
    */
    if((ch >= '0') && (ch <= '9'))
         return ch-0x30;
     else if((ch >= 'A') && (ch <= 'F'))
         return ch-'A'+10;
     else if((ch >= 'a') && (ch <= 'f'))
         return ch-'a'+10;
     else return (-1);
}

/**
    * @name		ReadLineChars
    * @brief  	读取目标行文件内容
  */
QString ReadLineChars(FILE* fp, uint32_t line)
{
    uint32_t i;
    char buf[128];
    for(i = 0; i <= line; i++)
    {
        fgets(buf, 128, fp);
        if(i == line)
        {
            if(buf[strlen(buf) - 1] == '\n')
            {
                buf[strlen(buf) - 1] = '\0';
            }
            fseek(fp, 0L,SEEK_SET);
            return QString(buf);
        }
    }
    return "error";
}
