#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QVector>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
//    this->setMouseTracking(true);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e) {

    // make a canvas on while dialog
    QPainter painter(this);

    QPen pen(QColor(115, 115, 115));
    pen.setWidth(1);

    QPen linePen(QColor(230, 230, 230));
    linePen.setWidth(1);
    painter.setPen(linePen);

    // draw a patterns lines
    for(int i = 0; i < this->width(); i+=11) {
        painter.drawLine(i, 0, i, this->height());
    }
    for(int i = 0; i < this->height(); i+=11) {
        painter.drawLine(0, i, this->width(), i);
    }

    // fill whole area with dark squares.
    QBrush brush(QColor(115, 115, 115));
    QVector<QRect> rects;
    for(int i = 0; i < this->width(); i+=11) {
        for(int j = 0; j < this->height(); j+=11) {
            rects.push_back(QRect(i+1, j+1, 10, 10));
            painter.fillRect(rects.back(), brush);  // just fill a squares, not draw borders
        }
    }


    //painter.fillRect(rect, brush);
    //painter.drawLine(p1, p2);
    //painter.drawRects(rects);


}

void Dialog::mouseMoveEvent(QMouseEvent *e) {
    qDebug() << "mouseEvent" << e->pos().x() << e->pos().y();
}
