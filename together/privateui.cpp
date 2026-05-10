#include "privateui.h"
#include "ui_privateui.h"
#include "myself.h"
#include "member.h"
#include "rank.h"
#include "mainwindow.h"

privateui::privateui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::privateui)
{
    ui->setupUi(this);
    //个人简介
    m_pmyself=new myself;
    connect(m_pmyself,SIGNAL(signalback()),this,SLOT(slotBack()));
    //工会成员
    m_pmember = new member;
    connect(m_pmember,SIGNAL(signalback()),this,SLOT(slotBack()));
    //积分榜
    m_prank = new rank;
    connect(m_prank,SIGNAL(signalback()),this,SLOT(slotBack()));
}

privateui::~privateui()
{
    delete ui;
}

void privateui::setID(int id)
{
    m_pID = id;
    if(id != 1)
        ui->pushButton_other->setVisible(false);
}
//个人简介
void privateui::on_pushButton_me_clicked()
{
    this->hide();
    m_pmyself->setID(m_pID);
    m_pmyself->show();
}

//工会成员
void privateui::on_pushButton_other_clicked()
{
    this->hide();
    m_pmember->show();
}


void privateui::on_pushButton_clicked()
{
    MainWindow *m=new MainWindow;
    m->show();
    delete(this);
}
//积分榜
void privateui::on_pushButton_ran_clicked()
{
    this->hide();
    m_prank->refreshData("ASC");
    m_prank->show();
}

void privateui::slotBack()
{
    this->show();
}
