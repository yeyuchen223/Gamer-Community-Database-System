#include "updatemember.h"
#include "ui_updatemember.h"
#include "stusql.h"

updatemember::updatemember(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updatemember)
{
    ui->setupUi(this);
}

updatemember::~updatemember()
{
    delete ui;
}

void updatemember::loadmemberInfo(memberInfo info)
{
    m_pmemberInfo = info;
    ui->lineEdit->setText(info.username);
    ui->lineEdit_2->setText(info.password);
    ui->lineEdit_3->setText(info.name);
    ui->lineEdit_4->setText(QString::number(info.integral));
}

void updatemember::on_pushButton_clicked()
{
    m_pmemberInfo.username = ui->lineEdit->text();
    m_pmemberInfo.password = ui->lineEdit_2->text();
    m_pmemberInfo.name = ui->lineEdit_3->text();
    m_pmemberInfo.integral = ui->lineEdit_4->text().toInt();
    stuSql::getinstance()->updatemember(m_pmemberInfo);
    emit signalfinish();
    this->hide();
}

void updatemember::on_pushButton_2_clicked()
{
    this->hide();
}
