#ifndef RANK_H
#define RANK_H

#include <QMainWindow>

namespace Ui {
class rank;
}

class rank : public QMainWindow
{
    Q_OBJECT

public:
    explicit rank(QWidget *parent = 0);
    ~rank();
    void refreshData(QString str);
signals:
    void signalback();
private slots:
    void on_pushButton_back_clicked();
    void on_pushButton_line_clicked();
private:
    Ui::rank *ui;
};

#endif // RANK_H
