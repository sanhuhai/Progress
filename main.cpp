#include "Progress.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Progress w;
    w.show();
    return a.exec();
}
