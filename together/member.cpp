#include "member.h"
#include "ui_member.h"
#include "privateui.h"
#include "stusql.h"
#include <QDebug>
#include "addmember.h"
#include <QMessageBox>

member::member(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::member)
{
    ui->setupUi(this);
    m_paddmember = new addmember();
    connect(m_paddmember,SIGNAL(signalOK()),this,SLOT(slotOK()));
    refreshData();
}

member::~member()
{
    delete ui;
}

void member::refreshData()
{
    ui->tableWidget->clear();
    //设置列数
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //去除选中虚线框
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);
    //表头标题用QStringList来表示
    QStringList headerText;
    headerText<<"序 号"<<"用户名"<<"昵 称"<<"积 分";
    ui->tableWidget->setHorizontalHeaderLabels(headerText);
    QList<memberInfo> info = stuSql::getinstance()->getmemberInfo();
    //设置行数
    ui->tableWidget->setRowCount(info.size()-1);
    for(int i = 1;i<info.size();i++)
    {
        ui->tableWidget->setItem(i-1,0,new QTableWidgetItem(QString::number(info.at(i).id)));
        ui->tableWidget->setItem(i-1,1,new QTableWidgetItem(info.at(i).username));
        ui->tableWidget->setItem(i-1,2,new QTableWidgetItem(info.at(i).name));
        ui->tableWidget->setItem(i-1,3,new QTableWidgetItem(QString::number(info.at(i).integral)));
    }
}

void member::on_pushButton_clicked()
{
    this->hide();
    emit signalback();
}

//添加成员
void member::on_pushButton_2_clicked()
{
    m_paddmember->cleardata();
    m_paddmember->show();
}

//踢出成员
void member::on_pushButton_3_clicked()
{
    if(ui->tableWidget->selectedItems().size() > 0)
    {
       int id = ui->tableWidget->selectedItems().at(0)->text().toInt();
        if(stuSql::getinstance()->delmember(id))
        {
            QMessageBox::warning(this,tr("提示"),tr("踢出成功！"),QMessageBox::Ok);
            refreshData();
        }
    }
}

void member::slotOK()
{
    refreshData();
}
