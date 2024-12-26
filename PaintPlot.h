#ifndef PAINTPLOT_H
#define PAINTPLOT_H
#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QPainter>

class CurvatureLensWidget : public QWidget {
public:
    explicit CurvatureLensWidget(QWidget* parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent* event) override {
        Q_UNUSED(event);

        QPainter painter(this);

        // 设置绘图属性
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setRenderHint(QPainter::HighQualityAntialiasing, true);

        // 获取窗口尺寸
        int width = this->width();
        int height = this->height();

        // 绘制曲率透镜
        drawCurvatureLens(&painter, width, height);
    }

    void drawCurvatureLens(QPainter* painter, int width, int height) {
        // 设置曲率透镜的颜色
        painter->setBrush(QBrush(Qt::blue));

        // 计算曲率透镜的位置和大小
        int lensWidth = width / 2;
        int lensHeight = height / 2;
        int lensX = (width - lensWidth) / 2;
        int lensY = (height - lensHeight) / 2;

        // 绘制椭圆形状的曲率透镜
        painter->drawEllipse(lensX, lensY, lensWidth, lensHeight);
    }
};


#endif // PAINTPLOT_H
