/*
 * Copyright (C), 1988-1999, Xxxxxx Tech. Co., Ltd.
 * FileName: main.cpp
 * Description: main函数
 * Change Logs:
  |Date          |Author       |Notes     			|version
  |2022-09-17    |满心欢喜     |Initial build     	|1.0.0
 */

/*  @include  */
#include "MainWindow.h"
#include <QSharedMemory>
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSharedMemory shared_memory;

    shared_memory.setKey(QString("RLCOM"));

    if(shared_memory.attach())
    {

        QMessageBox::about(NULL, "提示","程序已经在运行！");

        return 0;
    }

    if(shared_memory.create(1))
    {

        MainWindow ui;

        QFile file("blacksoft.css");

        if(file.open(QFile::ReadOnly))
        {
            QString qss = QLatin1String(file.readAll());

            QString paletteColor = qss.mid(20, 7);

            ui.setPalette(QPalette(QColor(paletteColor)));

            ui.setStyleSheet(qss);

            file.close();
        }
        ui.show();

        return app.exec();
    }
    return 0;
}

