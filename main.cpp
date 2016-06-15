#include "ctwrt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CTWRT w;
    w.show();

    return a.exec();
}
