#include "mainwindow.h"
#include <QApplication>
#include  <client.h>
#include "loginform.h"#include "loginform.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    client *aclient = new client(5000, "127.1.1.2");
    return a.exec();
}
