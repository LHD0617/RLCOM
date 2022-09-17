#include "MainWindow.h"
#include <QSharedMemory>
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSharedMemory shared_memory;

    shared_memory.setKey(QString("9982"));

    if(shared_memory.attach())
    {

        QMessageBox::about(NULL, "提示","程序已经在运行！");

        return 0;
    }

    if(shared_memory.create(1))
    {
        MainWindow ui;

        QFile file("flatgray.css");

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

