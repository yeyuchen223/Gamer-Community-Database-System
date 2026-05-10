#ifndef MYSELF_H
#define MYSELF_H

#include <QMainWindow>

class updatemember;

namespace Ui {
class myself;
}

class myself : public QMainWindow
{
    Q_OBJECT

public:
    explicit myself(QWidget *parent = 0);
    ~myself();
    void setID(int id);
signals:
    void signalback();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_back_clicked();
    void slotfinish();
private:
    Ui::myself *ui;
    updatemember* m_pupdatemember;
    int m_pID;
};

#endif // MYSELF_H
