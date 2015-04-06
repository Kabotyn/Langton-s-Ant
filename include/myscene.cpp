#include "myscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

MyScene::MyScene(QObject *parent, int w, int h)
{
    setSceneRect(0, 0, w, h);
    qDebug() << w << h;
    for(int i = 0; i < w; i+=11) {
        addLine(i,0, i, h, QPen(Qt::magenta));
    }

    for(int i = 0; i < h; i+=11) {
        addLine(0,i, w, i, QPen(Qt::magenta));
    }

}

MyScene::~MyScene()
{

}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e) {
   // qDebug() << e->scenePos().x() << e->scenePos().y();

}
