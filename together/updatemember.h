#ifndef UPDATEMEMBER_H
#define UPDATEMEMBER_H

#include <QWidget>
#include "stusql.h"

namespace Ui {
class updatemember;
}

class updatemember : public QWidget
{
    Q_OBJECT

public:
    explicit updatemember(QWidget *parent = nullptr);
    ~updatemember();
    //加载信息
    void loadmemberInfo(memberInfo info);
signals:
    void signalfinish();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::updatemember *ui;
    memberInfo m_pmemberInfo;
};

#endif // UPDATEMEMBER_H
