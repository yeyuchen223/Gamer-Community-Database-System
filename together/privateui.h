#ifndef PRIVATEUI_H
#define PRIVATEUI_H

#include <QMainWindow>

class myself;
class member;
class rank;

namespace Ui {
class privateui;
}

class privateui : public QMainWindow
{
    Q_OBJECT

public:
    explicit privateui(QWidget *parent = 0);
    ~privateui();
    void setID(int id);
private slots:
    void on_pushButton_me_clicked();

    void on_pushButton_other_clicked();

    //void on_pushButton_note_clicked();

    //void on_pushButton_rank_clicked();

    void on_pushButton_clicked();

    void on_pushButton_ran_clicked();

    void slotBack();

private:
    Ui::privateui *ui;
    myself *m_pmyself;
    member *m_pmember;
    rank *m_prank;
    int m_pID;
};

#endif // PRIVATEUI_H
