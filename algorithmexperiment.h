#ifndef ALGORITHMEXPERIMENT_H
#define ALGORITHMEXPERIMENT_H

#include <QWidget>
#include <QFile>
#include <QDataStream>
#include <QDebug>



#include <qwt_plot.h>
#include <qwt_plot.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_curve.h>
#include <qwt_legend.h>
#include <qwt_point_data.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_text.h>
#include <qwt_symbol.h>
#include <qwt_math.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_directpainter.h>

namespace Ui {
class AlgorithmExperiment;
}


//  ConvexHull Data
#define CONVEX_BRUTEFORCE_FILE  "./ConvexHull/BruteForceOutput.txt"
#define CONVEX_GRAHAMSCAN_FILE  "./ConvexHull/GrahamScanOutput.txt"
#define CONVEX_DIVIDE_FILE "./ConvexHull/DivideOutput.txt"


class AlgorithmExperiment : public QWidget
{
    Q_OBJECT

public:
    explicit AlgorithmExperiment(QWidget *parent = 0);
    ~AlgorithmExperiment();


private slots:
    void slotShowConvexHullPlot();      //
    void slotShowBruteConvexHullPlot();
    void slotShowScanConvexHullPlot();
    void slotShowDivideConvexHullPlot();

    void slotShowQwtPlot(int index);

private:
    Ui::AlgorithmExperiment *ui;

    QwtPlotGrid *m_grid;            //  网格

//    QwtPlotMarker  *m_marker;
    //  暴力求解凸包
    QwtPlotCurve *m_curveConvexBrute;
    QPen m_penConvexBrute;

    //  扫描法求解凸包
    QwtPlotCurve *m_curveConvexScan;
    //QPen m_penConvexScan;

    //  扫描法求解凸包
    QwtPlotCurve *m_curveConvexDivide;
   // QPen m_penConvexDivide;
};

#endif // ALGORITHMEXPERIMENT_H
