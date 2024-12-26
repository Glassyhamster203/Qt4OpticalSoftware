#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    float a[6] = {1.320,0.133,0.886,0.009,0.042,111.729};


    ui->label_16->setPixmap(QPixmap("://layout/res/Formual.jpg"));
    ui->label_17->setText("Sellmeier Formula:");
        ui->tableWidget->setColumnCount(2);//只设置列数，行数动态中增加
        ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<QString::fromUtf8("色散系数")
                                                            <<QString::fromUtf8("数值"));
        ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中的方式
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止修改
        ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);//可以选中单个

        for (int i = 0 ;i < 6  ;i++ ) {
            int RowCont=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(RowCont);//增加一行
            ui->tableWidget->setItem(RowCont,0,new QTableWidgetItem(QString::asprintf("a%d",i+1)));
            ui->tableWidget->setItem(RowCont,1,new QTableWidgetItem(QString::asprintf("%.3f",a[i])));

        }
}

Dialog::~Dialog()
{
    delete ui;
}
