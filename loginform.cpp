#include "loginform.h"
#include <QDebug>
#include "singleton.h"
#include <QByteArray>
#include  "string.h"

#include "ui_loginform.h"
loginForm::loginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginForm)
{
    ui->setupUi(this);
}

loginForm::~loginForm()
{
    delete ui;
}

void loginForm::on_pushButton_clicked()
{
    Singleton& clients = Singleton::getInstance();
    this->username  = ui->lineEdit->text();
    this->password  = ui->lineEdit_2->text();
    QByteArray byteName = this->username.toUtf8();
    char* message = (char*)malloc(sizeof(char*));
    char* name   = byteName.data();
//    qDebug()<<(this->username);
    printf("Butoon clicked\n%s!\n", name);
    message = clients.sendandrecieve(name);
    printf("MMesssage =%s\n", message);
    if(strcmp(message, "Ok") == 0){
        printf("Cloose\n");
        clients.f->hide();
        clients.w->show();
    }
    return;
}

void loginForm::closeEvent(QCloseEvent* event){
    Singleton& clients = Singleton::getInstance();
    clients.closeConection();
}

