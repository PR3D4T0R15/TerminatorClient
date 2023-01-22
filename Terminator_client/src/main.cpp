#include "loginwindow.h"
#include "network.h"
#include <QtWidgets/QApplication>
#include <QNetworkRequest>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginWindow window;
    window.show();
    return a.exec();
}
