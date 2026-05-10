#ifndef STUSQL_H
#define STUSQL_H

#include <QObject>
#include <QSqlDatabase>
struct memberInfo
{
    int id;
    QString username;
    QString password;
    QString name;
    int integral;
};

class stuSql : public QObject
{
    Q_OBJECT
public:
    static stuSql *ptrstuSql;
    static stuSql *getinstance()
    {
         if(nullptr == ptrstuSql)
         {
            ptrstuSql = new stuSql;
         }
         return ptrstuSql;
    }

    explicit stuSql(QObject *parent = nullptr);

    void init();

    //查询成员
    QList<memberInfo> getmemberInfo();
    QList<memberInfo> getmemberInfo(QString str);
    //增加成员
    bool addmember(memberInfo info);
    //删除成员
    bool delmember(int id);
    //修改成员
    bool updatemember(memberInfo info);
signals:
private:
    QSqlDatabase m_db;
};

#endif // STUSQL_H

