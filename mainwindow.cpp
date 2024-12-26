#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include "calc.h"
#include <QImage>
#include <QPixmap>
#include "help_dialog.h"

// using namespace std;
singleLen Len;
Double_sided_spherical Len_2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //    std::cout << "114514" << std::endl;

    Len_2.setLenParameter(ui->doubleSpinBox_7->value(),\
                          ui->doubleSpinBox->value(),\
                          ui->doubleSpinBox_5->value(),\
                          ui->doubleSpinBox_6->value());
//


    Len_2.calcFocal();
    Len_2.setObjectDistance(ui->doubleSpinBox_2->value());
    ui->label_10->setNum(Len_2.calcImageDistance());
    ui->label_7->setNum(Len_2.calcAlpha());
    ui->label_8->setNum(Len_2.calcBeta());
    ui->label_9->setNum(Len_2.calcGamma());

    ui->doubleSpinBox_4->setValue(Len_2.getFocal());

    std::cout << "114514" << std::endl;
}

void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
//    std::cout << arg1 << "Spin 1" << std::endl;
//    Len.setfocalLength(arg1);
}

void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
//    std::cout << arg1 << "Spin 2" << std::endl;
//    Len.setObjectDistance(arg1);
}

void MainWindow::on_pushButton_2_clicked()
{
    QVector<double> WaveLength(360), y(360);
    QVector<double> face1_x(500), face1_y(500);
    QVector<double> face2_x(500), face2_y(500);
    int j = 0;
    double phi = 50;
    QPen standPen;
    standPen.setWidth(3);


    double P_r2 = abs(Len_2.imageMainPointLength) + abs(Len_2.thickNess) - abs(Len_2.secondRadius);
    double P_r1 = abs(Len_2.imageMainPointLength) + abs(Len_2.firstRadius);


    double angle_step1 = abs(atan2(phi/2,abs(Len_2.firstRadius))/500);
    double angle_step2 = abs(atan2(phi/2,abs(Len_2.secondRadius))/500);

    for(int i = 0; i<500 ;i++){
        face1_x[i] = -abs(Len_2.firstRadius) * cos( angle_step1 * (i-250)) + P_r1;
        face1_y[i] = abs(Len_2.firstRadius) * sin( angle_step1 * (i-250));
        face2_x[i] = abs(Len_2.secondRadius) * cos( angle_step2 * (i-250)) + P_r2;
        face2_y[i] = abs(Len_2.secondRadius) * sin( angle_step2 * (i-250));
    }



    ui->seqPlot->addGraph();
    ui->seqPlot->graph(0)->setData(face1_x,face1_y);
    ui->seqPlot->addGraph();
    ui->seqPlot->graph(1)->setData(face2_x,face2_y);
    ui->seqPlot->xAxis2->setVisible(false);

    QPen pen;
    pen.setWidth(3);//线宽
        // 添加Graph，1条曲线使用一个Graph
    ui->seqPlot->addGraph();
    pen.setStyle(Qt::PenStyle::DashLine);//虚线
    pen.setColor(Qt::yellow);//黄色
    ui->seqPlot->graph(2)->setPen(pen);
//    ui->seqPlot->graph(2)->setData(,{-10,10});



    QPen pen1;
    pen1.setWidth(3);//线宽
        // 添加Graph，1条曲线使用一个Graph
    ui->seqPlot->addGraph();
    pen1.setStyle(Qt::PenStyle::DashLine);//虚线
    pen1.setColor(Qt::yellow);//黄色
    ui->seqPlot->graph(3)->setPen(pen1);


    ui->seqPlot->xAxis->setRange(-20,20);
    ui->seqPlot->xAxis->setTickLength(20);
    ui->seqPlot->yAxis->setTickLength(20);
    ui->seqPlot->yAxis2->setVisible(false);
    ui->seqPlot->yAxis->setRange(-20,20);

    ui->seqPlot->xAxis->setVisible(false);
    ui->seqPlot->yAxis->setVisible(false);

//    ui->seqPlot->xAxis->rescale(false);
//    ui->seqPlot->yAxis->rescale(false);

    ui->seqPlot->replot();


    for (double i = Min_Wavelength; i < Max_Wavelength; i+=0.001)
    {
        WaveLength[j] = i;
        y[j] = Len_2.calcAbel(i);
        j++;
    }
    ui->customplot->setOpenGl(true);
    ui->customplot->addGraph();
    ui->customplot->graph(0)->setData(y, WaveLength);
    // give the axes some labels:
    ui->customplot->xAxis->setLabel("focal shift");
    ui->customplot->yAxis->setLabel("wavelength (um)");
    // set axes ranges, so we see all data:
    ui->customplot->yAxis->setRange(Min_Wavelength, Max_Wavelength);
    ui->customplot->xAxis->rescale(true);
    ui->customplot->replot();


//    if((Len_2.firstRadius + Len_2.secondRadius) >= 5) ui->label_17->setPixmap(QPixmap(":/layout/res/R2lessR1.png"));
//    else if((Len_2.firstRadius + Len_2.secondRadius) <= 5&&(Len_2.firstRadius + Len_2.secondRadius) >= -5) ui->label_17->setPixmap(QPixmap(":/layout/res/R2equalR1.png"));
//    else if ((Len_2.secondRadius + Len_2.firstRadius) <= -5) ui->label_17->setPixmap(QPixmap(":/layout/res/R1lessR2.png"));
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
//    Len_2.setLenParameter(0,arg1,0,0);
}


void MainWindow::on_doubleSpinBox_8_valueChanged(double arg1)
{
   Len_2.setAbel(arg1);
}


void MainWindow::on_actionSave_triggered()
{

}


void MainWindow::on_pushButton_3_clicked()
{
    dia.exec();
}

