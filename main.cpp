#include "mainwindow.h"
#include <QApplication>
#include  <client.h>
#include "loginform.h"
#include "singleton.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Singleton& clients = Singleton::getInstance();
//    client *aclient = new client(5000, "127.1.1.2");
//    clients.sendandrecieve("jko");
    return a.exec();
}
