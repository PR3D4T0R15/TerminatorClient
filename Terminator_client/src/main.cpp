#include "loginwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginWindow window;
    window.show();
    return a.exec();
}
