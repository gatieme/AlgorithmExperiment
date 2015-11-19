#include "algorithmexperiment.h"
#include "ui_algorithmexperiment.h"

AlgorithmExperiment::AlgorithmExperiment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlgorithmExperiment)
{
    ui->setupUi(this);
    this->ui->labelAlgExp->setScaledContents(true);

    // 设置画布背景
    this->ui->qwtPlotAlgExp->setCanvasBackground(QColor(29, 100, 141)); // nice blue

    // 增加网格
    this->m_grid = new QwtPlotGrid();
    this->m_grid->attach( this->ui->qwtPlotAlgExp);

    this->m_legend = new QwtLegend();
    //this->m_legend->setDefaultItemMode( QwtLegendData::Checkable );//图例可被点击
    this->ui->qwtPlotAlgExp->insertLegend(this->m_legend, QwtPlot::RightLegend );

    ////////////////////////////
    ///  设置凸包的图层
    ////////////////////////////
    // 凸包暴力曲线  颜色红色
    this->m_curveConvexBrute=new QwtPlotCurve("暴力法");
    this->m_curveConvexBrute->setRenderHint(QwtPlotItem::RenderAntialiased,true);      //抗锯齿
   // this->m_curveConvexBrute->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    this->m_curveConvexBrute->setLegendAttribute(this->m_curveConvexBrute->LegendShowLine);

    //  GrahamScan扫描算法曲线  颜色蓝色
    this->m_curveConvexScan=new QwtPlotCurve("扫描法");
    this->m_curveConvexScan->setRenderHint(QwtPlotItem::RenderAntialiased, true);      //抗锯齿
    this->m_curveConvexScan->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    this->m_curveConvexScan->setLegendAttribute(this->m_curveConvexScan->LegendShowLine);


    this->m_curveConvexDivide =new QwtPlotCurve("分治法");
    this->m_curveConvexDivide->setRenderHint(QwtPlotItem::RenderAntialiased, true);      //抗锯齿
    this->m_curveConvexDivide->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    this->m_curveConvexDivide->setLegendAttribute(this->m_curveConvexDivide->LegendShowLine);



   // panning with the left mouse button支持鼠标平移
   ( void ) new QwtPlotPanner( this->ui->qwtPlotAlgExp->canvas() );
   // zoom in/out with the wheel支持滚轮放大缩小
   ( void ) new QwtPlotMagnifier( this->ui->qwtPlotAlgExp->canvas() );


    this->connect(this->ui->comboBoxAlgExp, SIGNAL(currentIndexChanged(int)), this, SLOT(slotShowQwtPlot(int)));


    this->slotShowQwtPlot(this->ui->comboBoxAlgExp->currentIndex());

}

AlgorithmExperiment::~AlgorithmExperiment()
{
    delete ui;
    delete m_grid;            //  网格
    delete m_legend;
    delete m_curveConvexBrute;
    delete m_curveConvexScan;
    delete m_curveConvexDivide;
}

void AlgorithmExperiment::slotShowQwtPlot(int index)
{
    qDebug() <<this->ui->comboBoxAlgExp->currentIndex()  <<"  " <<this->ui->comboBoxAlgExp->currentText() <<endl;
    switch(index)
    {
        case 0:
        {
            this->slotShowConvexHullPlot();
            break;
        }
        case 1:
        {
            this->slotShowHamiltonianPlot();
            break;
        }
    }

}


void AlgorithmExperiment::slotShowConvexHullPlot( )
{
    this->slotShowBruteConvexHullPlot();        // 暴力法曲线
    this->slotShowScanConvexHullPlot();
    this->slotShowDivideConvexHullPlot();

    this->ui->qwtPlotAlgExp->replot();
}



void AlgorithmExperiment::slotShowBruteConvexHullPlot( )
{
    qDebug( ) <<"凸包问题--ConbexHull" <<endl;
    QVector<double> xData;
    double  minxData =100000000 , maxxData = 0;
    QVector<double> yData;
    double minyData = 100000000, maxyData = 0;
    int datasize, timeuse, count;
    xData <<0;
    yData <<0;
    count = 1;
    //this->m_marker->attach(  this->ui->qwtPlotAlgExp);

    QFile file(CONVEX_BRUTEFORCE_FILE);
    if (file.open(QIODevice::ReadOnly) ==false)
    {
        qDebug() <<"打开文件失败" <<CONVEX_BRUTEFORCE_FILE <<endl;
        return ;
    }
    qDebug() <<"打开文件成功" <<CONVEX_BRUTEFORCE_FILE <<endl;
    QTextStream in(&file);
    qDebug() <<in.atEnd() <<endl;
    while(in.atEnd() != true)
    {
        //qDebug() <<"读取信息" <<endl;
        in >>datasize >>timeuse;
        //qDebug() <<"datesize = " <<datasize <<", timeuse = " <<timeuse <<endl;
        xData <<datasize;
        yData <<timeuse;
        count++;


       if(datasize< minxData)
       {
           minxData = datasize;
       }
       else if(datasize > maxxData)
       {
           maxxData = datasize;
       }

       if(timeuse < minyData)
       {
           minyData = timeuse;
       }
       if(timeuse > maxyData)
       {
           maxyData = timeuse;
       }
    }
   qDebug( ) <<"水平间距 X坐标范围" <<minxData <<"--" <<maxxData <<endl;
   qDebug( ) <<"垂直间距 Y坐标范围" <<minyData <<"--" <<maxyData <<endl;

   // 设置坐标轴
   this->ui->qwtPlotAlgExp->setAxisTitle(QwtPlot::xBottom, "数据量" );
   this->ui->qwtPlotAlgExp->setAxisScale(QwtPlot::xBottom, (int)minxData- 1, (int)maxxData + 1);
   this->ui->qwtPlotAlgExp->setAxisTitle(QwtPlot::yLeft, "时间" );
   this->ui->qwtPlotAlgExp->setAxisScale(QwtPlot::yLeft, (int)minyData - 1, (int)maxyData + 1);

    this->m_curveConvexBrute->setSamples(xData, yData);
    this->m_curveConvexBrute->attach( this->ui->qwtPlotAlgExp);
    this->m_curveConvexBrute->setLegendAttribute( QwtPlotCurve::LegendShowLine, true );
    this->m_curveConvexBrute->setStyle( QwtPlotCurve::NoCurve );
    this->m_curveConvexBrute->setSymbol( new QwtSymbol( QwtSymbol::XCross, Qt::NoBrush, QPen( Qt::red ), QSize(5, 5 ) ) );


}

void AlgorithmExperiment::slotShowScanConvexHullPlot()
{
    qDebug( ) <<"凸包问题--扫描算法ConbexHull" <<endl;
    QVector<double> xScanData;
    double  minxData = 100000000, maxxData = 0;
    QVector<double> yScanData;
    double minyData = 100000000, maxyData = 0;
    long datasize, timeuse, count;
    xScanData <<0;
    yScanData <<0;
    count = 1;
    //this->m_marker->attach(  this->ui->qwtPlotAlgExp);

    QFile file(CONVEX_GRAHAMSCAN_FILE);
    if (file.open(QIODevice::ReadOnly) ==false)
    {
        qDebug() <<"打开文件失败" <<CONVEX_GRAHAMSCAN_FILE <<endl;
        return ;
    }
    qDebug() <<"打开文件成功" <<CONVEX_GRAHAMSCAN_FILE <<endl;
    QTextStream in(&file);
    //qDebug() <<in.atEnd() <<endl;
    while(in.atEnd() != true)
    {
        //qDebug() <<"读取信息" <<endl;
        in >>datasize >>timeuse;
        //qDebug() <<"datesize = " <<datasize <<", timeuse = " <<timeuse <<endl;
        xScanData <<datasize;
        yScanData <<timeuse;
        count++;


       if(datasize< minxData)
       {
           minxData = datasize;
       }
       else if(datasize > maxxData)
       {
           maxxData = datasize;
       }

       if(timeuse < minyData)
       {
           minyData = timeuse;
       }
       if(timeuse > maxyData)
       {
           maxyData = timeuse;
       }
    }
   qDebug( ) <<"水平间距 X坐标范围" <<minxData <<"--" <<maxxData <<endl;
   qDebug( ) <<"垂直间距 Y坐标范围" <<minyData <<"--" <<maxyData <<endl;

   // 设置坐标轴
   this->ui->qwtPlotAlgExp->setAxisTitle(QwtPlot::xBottom, "数据量" );
   this->ui->qwtPlotAlgExp->setAxisScale(QwtPlot::xBottom, (int)minxData- 1, (int)maxxData + 1);
   this->ui->qwtPlotAlgExp->setAxisTitle(QwtPlot::yLeft, "时间" );
   this->ui->qwtPlotAlgExp->setAxisScale(QwtPlot::yLeft, (int)minyData - 1, (int)maxyData + 1);

    this->m_curveConvexScan->setSamples(xScanData, yScanData);
    this->m_curveConvexScan->attach( this->ui->qwtPlotAlgExp);

   this->m_curveConvexScan->setStyle( QwtPlotCurve::NoCurve );
    this->m_curveConvexScan->setSymbol( new QwtSymbol( QwtSymbol::XCross, Qt::NoBrush, QPen( Qt::blue ), QSize(5, 5) ) );

}


void AlgorithmExperiment::slotShowDivideConvexHullPlot()
{
    qDebug( ) <<"凸包问题--分治算法ConbexHull" <<endl;
    QVector<double> xDivideData;
    double  minxData = 100000000, maxxData = 0;
    QVector<double> yDivideData;
    double minyData = 100000000, maxyData = 0;
    int datasize, timeuse, count;
    xDivideData <<0;
    yDivideData <<0;
    count = 1;
    //this->m_marker->attach(  this->ui->qwtPlotAlgExp);

    QFile file(CONVEX_DIVIDE_FILE);
    if (file.open(QIODevice::ReadOnly) ==false)
    {
        qDebug() <<"打开文件失败" <<CONVEX_DIVIDE_FILE <<endl;
        return ;
    }
    qDebug() <<"打开文件成功" <<CONVEX_DIVIDE_FILE <<endl;
    QTextStream in(&file);
    //qDebug() <<in.atEnd() <<endl;
    while(in.atEnd() != true)
    {
        //qDebug() <<"读取信息" <<endl;
        in >>datasize >>timeuse;
        //qDebug() <<"datesize = " <<datasize <<", timeuse = " <<timeuse <<endl;
        xDivideData <<datasize;
        yDivideData <<timeuse;
        count++;


       if(datasize< minxData)
       {
           minxData = datasize;
       }
       else if(datasize > maxxData)
       {
           maxxData = datasize;
       }

       if(timeuse < minyData)
       {
           minyData = timeuse;
       }
       if(timeuse > maxyData)
       {
           maxyData = timeuse;
       }
    }
   qDebug( ) <<"水平间距 X坐标范围" <<minxData <<"--" <<maxxData <<endl;
   qDebug( ) <<"垂直间距 Y坐标范围" <<minyData <<"--" <<maxyData <<endl;

   // 设置坐标轴
   this->ui->qwtPlotAlgExp->setAxisTitle(QwtPlot::xBottom, "数据量" );
   this->ui->qwtPlotAlgExp->setAxisScale(QwtPlot::xBottom, (int)minxData- 1, (int)maxxData + 1);
   this->ui->qwtPlotAlgExp->setAxisTitle(QwtPlot::yLeft, "时间" );
   this->ui->qwtPlotAlgExp->setAxisScale(QwtPlot::yLeft, (int)minyData - 1, (int)maxyData + 1);

    this->m_curveConvexDivide->setSamples(xDivideData, yDivideData);
    this->m_curveConvexDivide->attach( this->ui->qwtPlotAlgExp);

    this->m_curveConvexDivide->setStyle( QwtPlotCurve::NoCurve );
    this->m_curveConvexDivide->setSymbol( new QwtSymbol( QwtSymbol::XCross, Qt::NoBrush, QPen( Qt::black ), QSize(5, 5) ) );
}


void AlgorithmExperiment::slotShowHamiltonianPlot()
{

}
