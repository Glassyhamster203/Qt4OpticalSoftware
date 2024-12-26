#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void on_radioButton_clicked();

    void on_pushButton_clicked();

//    void on_doubleSpinBox_valueChanged(double arg1);

//    void on_doubleSpinBox_2_textChanged(const QString &arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_pushButton_2_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_8_valueChanged(double arg1);

    void on_actionSave_triggered();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Dialog dia;
};
#endif // MAINWINDOW_H
