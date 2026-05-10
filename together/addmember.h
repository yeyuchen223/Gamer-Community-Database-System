#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QWidget>

namespace Ui {
class addmember;
}

class addmember : public QWidget
{
    Q_OBJECT

public:
    explicit addmember(QWidget *parent = nullptr);
    ~addmember();
    //清空界面数据
    void cleardata();
signals:
    void signalOK();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::addmember *ui;
};

#endif // ADDMEMBER_H
