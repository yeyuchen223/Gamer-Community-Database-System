#ifndef MEMBER_H
#define MEMBER_H

#include <QMainWindow>

class addmember;

namespace Ui {
class member;
}

class member : public QMainWindow
{
    Q_OBJECT

public:
    explicit member(QWidget *parent = 0);
    ~member();
    void refreshData();
signals:
    void signalback();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void slotOK();
private:
    Ui::member *ui;
    addmember* m_paddmember;
};

#endif // MEMBER_H
