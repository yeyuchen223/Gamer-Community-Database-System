#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "privateui.h"
#include <QMessageBox>
#include "stusql.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stuSql::getinstance()->init();
    m_pPrivateui=new privateui;
    ui->lineEdit_ID->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//登录按钮
void MainWindow::on_pushButton_clicked()
{
    bool flag = false;
    QList<memberInfo> info = stuSql::getinstance()->getmemberInfo();
    for(int i = 0;i<info.size();i++)
    {
        if(ui->lineEdit_ID->text() == info.at(i).username && ui->lineEdit_pw->text() == info.at(i).password)
        {
            m_pPrivateui->setID(info.at(i).id);
            flag = true;
            break;
        }
    }
    if(flag)
    {
        this->hide();
        m_pPrivateui->show();
    }
    else
    {
        QMessageBox::warning(this,tr("登录失败"),tr("用户名或密码输入错误！"),QMessageBox::Ok);
        ui->lineEdit_ID->clear();
        ui->lineEdit_pw->clear();
        ui->lineEdit_ID->setFocus();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}
