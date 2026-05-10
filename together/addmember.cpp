#include "addmember.h"
#include "ui_addmember.h"
#include "stusql.h"
#include <QMessageBox>

addmember::addmember(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addmember)
{
    ui->setupUi(this);
}

addmember::~addmember()
{
    delete ui;
}

void addmember::cleardata()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
}

void addmember::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() || ui->lineEdit_3->text().isEmpty() || ui->lineEdit_4->text().isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("不能为空！"),QMessageBox::Ok);
        return;
    }
    memberInfo info;
    info.username = ui->lineEdit->text();
    info.password = ui->lineEdit_2->text();
    info.name = ui->lineEdit_3->text();
    info.integral = ui->lineEdit_4->text().toInt();
    stuSql::getinstance()->addmember(info);
    this->hide();
    emit signalOK();
}

void addmember::on_pushButton_2_clicked()
{
    this->hide();
}
