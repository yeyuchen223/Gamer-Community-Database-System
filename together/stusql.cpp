#include "stusql.h"

#include <QMessageBox>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>

stuSql * stuSql::ptrstuSql = nullptr;
stuSql::stuSql(QObject *parent)
    : QObject{parent}
{
}

void stuSql::init()
{
    if (QSqlDatabase::drivers().isEmpty())
        qDebug()<<"No database drivers found";

    m_db = QSqlDatabase::addDatabase("QSQLITE");
#if 1
    auto str = QCoreApplication::applicationDirPath()+"/test.db";
    qDebug()<<str;
#endif
//    str = "G:\\data.db";
   m_db.setDatabaseName(str);
    if (!m_db.open())
       qDebug()<<"dbz not open";

}

QList<memberInfo> stuSql::getmemberInfo()
{
    QList<memberInfo> l;
    QSqlQuery sql(m_db);
    QString strsql = QString("select * from member");
    sql.exec(strsql);

    memberInfo info;
    while(sql.next())
    {
        info.id =  sql.value(0).toUInt();
        info.username = sql.value(1).toString();
        info.password = sql.value(2).toString();
        info.name =  sql.value(3).toString();
        info.integral = sql.value(4).toInt();
        l.push_back(info);
    }
    return l;
}

QList<memberInfo> stuSql::getmemberInfo(QString str)
{
    QList<memberInfo> l;
    QSqlQuery sql(m_db);
    QString strsql = QString("select * from member where ID > 1 order by integral %1").arg(str);
    sql.exec(strsql);

    memberInfo info;
    while(sql.next())
    {
        info.id =  sql.value(0).toUInt();
        info.username = sql.value(1).toString();
        info.password = sql.value(2).toString();
        info.name =  sql.value(3).toString();
        info.integral = sql.value(4).toInt();
        l.push_back(info);
    }
    return l;
}

bool stuSql::addmember(memberInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql= QString("insert into member values(null,'%1','%2','%3',%4)").
            arg(info.username).
            arg(info.password).
            arg(info.name).
            arg(info.integral);
    return sql.exec(strSql);
}

bool stuSql::delmember(int id)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from member where ID = %1").arg(id));
}

bool stuSql::updatemember(memberInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql= QString("update member set username='%1',password='%2',name='%3',integral=%4 where ID=%5").
            arg(info.username).
            arg(info.password).
            arg(info.name).
            arg(info.integral).arg(info.id);
    qDebug()<<strSql;
    bool ret =   sql.exec(strSql);
    QSqlError e =  sql.lastError();
    if(e.isValid())
    {
        qDebug()<<e.text();
    }
    return ret;
}

