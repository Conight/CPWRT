#include "ctwrt.h"
#include "ui_ctwrt.h"

CTWRT::CTWRT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CTWRT)
{
    ui->setupUi(this);
}

CTWRT::~CTWRT()
{
    delete ui;
}
