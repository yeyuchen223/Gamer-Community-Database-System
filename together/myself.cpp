#include "myself.h"
#include "ui_myself.h"
#include "privateui.h"
//D:\qt project\together\together\1000.jpg
#include <QDebug>
#include "stusql.h"
#include "updatemember.h"

myself::myself(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myself)
{
    ui->setupUi(this);

    QImage *img=new QImage;

    bool res = img->load("D:/qt project/together/together/12.png");
    qDebug() << "img" << res << img->isNull() << img->size();
    ui->label_pic->setPixmap(QPixmap::fromImage(*img));
    ui->label_pic->setScaledContents(true);
    qDebug() << "img" << img->size();
    m_pupdatemember = new updatemember;
    connect(m_pupdatemember,SIGNAL(signalfinish()),this,SLOT(slotfinish()));
}
myself::~myself()
{
    delete ui;
}

void myself::setID(int id)
{
    m_pID = id;
    QList<memberInfo> info = stuSql::getinstance()->getmemberInfo();
    for(int i = 0;i<info.size();i++)
    {
        if(info.at(i).id == id)
        {
            ui->label_5->setText(info.at(i).name);
            ui->label_6->setText(QString::number(info.at(i).id));
            if(info.at(i).id == 1)
                ui->label_7->setText(tr("会长"));
            else
                ui->label_7->setText(tr("成员"));
            ui->label_8->setText(QString::number(info.at(i).integral));
        }
    }

}

//编辑
void myself::on_pushButton_clicked()
{
    QList<memberInfo> info = stuSql::getinstance()->getmemberInfo();
    for(int i = 0;i<info.size();i++)
    {
        if(info.at(i).id == m_pID)
        {
            m_pupdatemember->loadmemberInfo(info.at(i));
            m_pupdatemember->show();
            break;
        }
    }
}

void myself::on_pushButton_back_clicked()
{
    emit signalback();
    this->hide();
}

void myself::slotfinish()
{
    QList<memberInfo> info = stuSql::getinstance()->getmemberInfo();
    for(int i = 0;i<info.size();i++)
    {
        if(info.at(i).id == m_pID)
        {
            ui->label_5->setText(info.at(i).name);
            ui->label_6->setText(QString::number(info.at(i).id));
            if(info.at(i).id == 1)
                ui->label_7->setText(tr("会长"));
            else
                ui->label_7->setText(tr("成员"));
            ui->label_8->setText(QString::number(info.at(i).integral));
        }
    }
}
