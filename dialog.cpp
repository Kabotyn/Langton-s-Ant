#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QVector>
#include <cmath>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //this->setMouseTracking(true);

    scene = new MyScene(this, 606, 441);

    //QGraphicsScene()
    //scene->setSceneRect(0, 0, 606, 441);
//    setMouseTracking(true);
    ui->graphicsView->setScene(scene);



    QBrush redBrush(Qt::red);
    QBrush bb(Qt::blue);
    QPen pen(Qt::black);
    pen.setWidth(1);
    //pen.setBrush(redBrush);

    rectancle = scene->addRect(1, 1, 9, 9, pen, redBrush);

    scene->addRect(12, 12, 9, 9, pen, bb);
    //scene->removeItem(rectancle);
    rectancle = scene->addRect(1, 12, 9, 9, pen, QBrush(Qt::yellow));
    //scene->removeItem(rectancle);


}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::mouseMoveEvent(QMouseEvent *e) {
    //QPoint p1;
    //p1 = ui->graphicsView->mapFrom(ui->graphicsView, e->pos());

    //qDebug() << p1.x() << p1.y();
    //scene->mouseMoveEvent();
}

void Dialog::on_pushButton_clicked()
{

//    for(int i = 0; i < ui->graphicsView->width(); i+=11) {
//        scene->addLine(i,0, i, 441, QPen(Qt::magenta));
//    }
//    for(int i = 0; i < ui->graphicsView->height(); i+=11) {
//        scene->addLine(0,i, 606, i, QPen(Qt::magenta));
//    }

}
