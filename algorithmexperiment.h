#ifndef ALGORITHMEXPERIMENT_H
#define ALGORITHMEXPERIMENT_H

#include <QWidget>
#include <QFile>
#include <QDataStream>
#include <QDebug>

namespace Ui {
class AlgorithmExperiment;
}


//  ConvexHull Data
#define CONVEX_BRUTEFORCE_FILE  "./ConvexHull/BruteForeOutput.txt"
#define CONVEX_GRAHAMSCAN_FILE  "./ConvexHull/GrahamOutput.txt"
#define CONVEX_DIVIDE_FILE "./ConvexHull/DivideOutput.txt"


class AlgorithmExperiment : public QWidget
{
    Q_OBJECT

public:
    explicit AlgorithmExperiment(QWidget *parent = 0);
    ~AlgorithmExperiment();


private slots:
    void slotShowConvexHullPlot();      //
    void slotShowQwtPlot(int index);
private:
    Ui::AlgorithmExperiment *ui;
};

#endif // ALGORITHMEXPERIMENT_H
