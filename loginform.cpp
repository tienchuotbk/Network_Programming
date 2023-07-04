#include "loginform.h"
#include <QDebug>

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
    this->username  = ui->lineEdit->text();
    this->password  = ui->lineEdit_2->text();
    qDebug()<<(this->username);
    printf("Butoon clicked!\n");
}

