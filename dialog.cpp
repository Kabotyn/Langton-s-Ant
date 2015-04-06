#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QVector>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    scene = new MyScene(this, 606, 441);

    ui->graphicsView->setScene(scene);      // add MyScene to graphicVie

    ant = new LangtonAnt(55, 40);
    int x, y, index;
//    index = ant->countTileIndex(3, 39);
//    ant->countTilePosXY(index, x, y);

    qDebug() << ant->getCurrentTile();
     ant->countTilePosXY(ant->getCurrentTile(), x, y);
    scene->addRect(x*11+1, y*11+1, 9 ,9 , QPen(QColor(115, 115, 115)), QBrush(QColor(115, 115, 115)));

    ant->move();
        qDebug() << ant->getCurrentTile();
         ant->countTilePosXY(ant->getCurrentTile(), x, y);
        scene->addRect(x*11+1, y*11+1, 9 ,9 , QPen(QColor(115, 115, 115)), QBrush(QColor(115, 115, 115)));

        ant->move();
            qDebug() << ant->getCurrentTile();
             ant->countTilePosXY(ant->getCurrentTile(), x, y);
            scene->addRect(x*11+1, y*11+1, 9 ,9 , QPen(QColor(115, 115, 115)), QBrush(QColor(115, 115, 115)));

}

Dialog::~Dialog()
{
    delete ui;
    delete ant;
    delete scene;
}
//void Dialog::mouseMoveEvent(QMouseEvent *e) {
    //QPoint p1;
    //p1 = ui->graphicsView->mapFrom(ui->graphicsView, e->pos());

    //qDebug() << p1.x() << p1.y();
    //scene->mouseMoveEvent();
//}

void Dialog::on_pushButton_clicked()
{
    scene->clear();
}
