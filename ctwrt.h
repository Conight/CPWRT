#ifndef CTWRT_H
#define CTWRT_H

#include <QMainWindow>

namespace Ui {
class CTWRT;
}

class CTWRT : public QMainWindow
{
    Q_OBJECT

public:
    explicit CTWRT(QWidget *parent = 0);
    ~CTWRT();

private:
    Ui::CTWRT *ui;
};

#endif // CTWRT_H
