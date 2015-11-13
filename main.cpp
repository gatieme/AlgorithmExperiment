#include "algorithmexperiment.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AlgorithmExperiment w;
    w.show();

    return a.exec();
}
