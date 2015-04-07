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

    QImage image(":/image/ant.png");
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    item->setPos(100, 100);
    item->setRotation(90);
    scene->addItem(item);

//    index = ant->countTileIndex(3, 39);
//    ant->countTilePosXY(index, x, y);
//    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));

    qDebug() << ant->getCurrentTile();
     ant->countTilePosXY(ant->getCurrentTile(), x, y);

     QColor q_white(255, 255, 255);
     QColor q_dark(115, 115, 115);

//    scene->addRect(x*11+1, y*11+1, 9 ,9 , QPen(ant->getCurrentTileColor() == white ? q_white : q_dark), QBrush(ant->getCurrentTileColor() == white ? q_white : q_dark));
//qDebug() << "-" << ant->getCurrentTile() << ant->getCurrentTileColor();
//    for(int i = 0; i < 30; i++) {
//        qDebug() << ant->getCurrentTile() << ant->getCurrentTileColor();
//        scene->addRect(x*11+1, y*11+1, 9 ,9 , QPen(ant->getCurrentTileColor() == white ? q_white : q_dark), QBrush(ant->getCurrentTileColor() == white ? q_white : q_dark));
//        ant->move();
//         ant->countTilePosXY(ant->getCurrentTile(), x, y);
//    }


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
