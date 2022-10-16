#ifndef PAY_H
#define PAY_H

#include <QMainWindow>


namespace Ui {
class Pay;
}

class Pay : public QMainWindow
{
    Q_OBJECT

public:
    explicit Pay(QWidget *parent = nullptr);
    ~Pay();


private slots:
    void on_pushButton_pay_clicked();

    void on_pushButton_return_clicked();

private:
    Ui::Pay *ui;
};

#endif // PAY_H
