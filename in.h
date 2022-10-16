#ifndef IN_H
#define IN_H

#include <QMainWindow>

namespace Ui {
class In;
}

class In : public QMainWindow
{
    Q_OBJECT

public:
    explicit In(QWidget *parent = 0);
    ~In();

private:
    Ui::In *ui;
};

#endif // IN_H
