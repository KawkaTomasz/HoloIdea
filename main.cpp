#include "holoidea.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HoloIdea w;
    w.show();

    return a.exec();
}
