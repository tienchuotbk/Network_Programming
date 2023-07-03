#include "loginform.h"
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
