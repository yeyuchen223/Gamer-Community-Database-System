#include "rank.h"
#include "ui_rank.h"
#include "privateui.h"
#include "stusql.h"
#include <QDebug>

rank::rank(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::rank)
{
    ui->setupUi(this);
    refreshData("ASC");
    connect(ui->radioButton_line, &QRadioButton::toggled, [=](bool isChecked){
        if (isChecked == true)
            refreshData("DESC");//倒序
        else if (isChecked == false)
            refreshData("ASC");//正序
        });
}

rank::~rank()
{
    delete ui;
}

void rank::refreshData(QString str)
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
    QList<memberInfo> info;
    info = stuSql::getinstance()->getmemberInfo(str);
    //设置行数
    ui->tableWidget->setRowCount(info.size());
    for(int i = 0;i<info.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(info.at(i).id)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(info.at(i).username));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(info.at(i).name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(info.at(i).integral)));
    }
}


void rank::on_pushButton_back_clicked()
{
    this->hide();
    emit signalback();
}

void rank::on_pushButton_line_clicked()
{
    refreshData("ASC");
}
