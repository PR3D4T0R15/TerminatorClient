#include "mainwindow.h"
#include "loginwindow.h"
#include "network.h"
#include <QtWidgets/QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    loginWindow window;
    window.show();

    mainWindow windowMain;

    //signals and slots
    QObject::connect(&window, &loginWindow::LoginSucces, &windowMain, &mainWindow::ShowWindow);
    

    return a.exec();
}
