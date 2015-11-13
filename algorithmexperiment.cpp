#include "algorithmexperiment.h"
#include "ui_algorithmexperiment.h"

AlgorithmExperiment::AlgorithmExperiment(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlgorithmExperiment)
{
    ui->setupUi(this);

    this->connect(this->ui->comboBoxAlgExp, SIGNAL(currentIndexChanged(int)), this, SLOT(slotShowQwtPlot(int)));
}

AlgorithmExperiment::~AlgorithmExperiment()
{
    delete ui;
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
            break;
        }
    }

}

// 显示定位信息
void AlgorithmExperiment::slotShowConvexHullPlot( )                // 显示定位信息
{
    qDebug( ) <<"凸包问题--ConbexHull" <<endl;
    QVector<double> xData;
    double  minxData = 1000, maxxData = 0;
    QVector<double> yData;
    double minyData = 1000, maxyData = 0;
    double datasize, timeuse;
    xData <<0;
    yData <<0;

    QFile file(CONVEX_BRUTEFORCE_FILE);
    if (file.open(QIODevice::ReadOnly) !=false)
    {
        qDebug() <<"打开文件失败" <<CONVEX_BRUTEFORCE_FILE <<endl;
    }
    qDebug() <<"打开文件成功" <<CONVEX_BRUTEFORCE_FILE <<endl;
    QTextStream in(&file);
    while(in.eof() != true)
    {
        in >>datasize >>timeuse;
        qDebug() <<"datesize = " <<datasize <<", timeuse = " <<timeuse <<endl;
        xData <<datasize;
        yData <<timeuse;
    }
    qDebug() <<"..." <<endl;
    /*this->m_locateLocalMarker->attach(  this->ui->plotLocate );


   for(int cnt = 0; cnt < count; cnt++)
   {
       position = &uNode->m_position;
       xData <<position->m_xdistance;          // 将经度写入X轴
       yData <<position->m_ydistance;             // 将维度写入Y轴

       marker = this->m_locateMarkerList.FindMarker(&uNode->m_user);
       marker->setValue( QPointF(position->m_xdistance, position->m_ydistance));
       marker->attach(  this->ui->plotLocate );

       if(position->m_xdistance < minxData)
       {
           minxData = position->m_xdistance;
       }
       if(position->m_xdistance > maxxData)
       {
           maxxData = position->m_xdistance;
       }

       if(position->m_ydistance < minyData)
       {
           minyData = position->m_ydistance;
       }
       if(position->m_ydistance > maxyData)
       {
           maxyData = position->m_ydistance;
       }

       uNode = uNode->m_next;
   }
   qDebug( ) <<"水平间距 X坐标范围" <<minxData <<"~~" <<maxxData <<endl;
   qDebug( ) <<"垂直间距 Y坐标范围" <<minyData <<"~~" <<maxyData <<endl;
   // 设置坐标轴
   this->ui->plotLocate->setAxisTitle(QwtPlot::xBottom, "East" );
   this->ui->plotLocate->setAxisScale(QwtPlot::xBottom, (int)minxData- 1, (int)maxxData + 1);

   this->ui->plotLocate->setAxisTitle(QwtPlot::yLeft, "North" );
   this->ui->plotLocate->setAxisScale(QwtPlot::yLeft, (int)minyData - 1, (int)maxyData + 1);

   // 增加网格
   //QwtPlotGrid *grid = new QwtPlotGrid;
   this->m_locateGrid->attach( this->ui->plotLocate);

   // 设置画布背景
   this->ui->plotLocate->setCanvasBackground(QColor(29, 100, 141)); // nice blue


   //新建一个曲线对象
   //tPlotCurve *pCurve=new QwtPlotCurve("route");
    this->m_locateCurve->setSamples(xData, yData);
    this->m_locateCurve->attach( this->ui->plotLocate);

    this->m_locateCurve->setStyle( QwtPlotCurve::NoCurve );
    this->m_locateCurve->setSymbol( new QwtSymbol( QwtSymbol::XCross,
       Qt::NoBrush, QPen( Qt::red ), QSize(5, 5 ) ) );
    //设置曲线颜色
    QPen pen;
    pen.setColor(QColor(255,0,0));

     this->m_locateCurve->setPen(pen);

   //QwtPlotCurve::PaintAttribute

   //抗锯齿
   this->m_locateCurve->setRenderHint(QwtPlotItem::RenderAntialiased,true);

   // panning with the left mouse button支持鼠标平移
   ( void ) new QwtPlotPanner( this->ui->plotLocate->canvas() );

   // zoom in/out with the wheel支持滚轮放大缩小
   ( void ) new QwtPlotMagnifier( this->ui->plotLocate->canvas() );

   //重绘
  this->ui->plotLocate->replot();*/
}

