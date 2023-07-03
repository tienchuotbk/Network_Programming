#include "mainwindow.h"
#include <QApplication>
#include  <client.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    client *aclient = new client(5000, "127.1.1.2");
    MainWindow w;
//    w.show();
    return a.exec();
}
