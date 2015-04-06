#include "myscene.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <cmath>

MyScene::MyScene(QObject *parent, int w, int h)
{
    width = w;
    height = h;
    setSceneRect(0, 0, width, height);
    drawGrid();
    qDebug() << width << height;

    rects.reserve(2200);
    rects.resize(2200);
    rects.fill(QRect(-10, -10, 0, 0));
//    rects.clear();

}


void MyScene::drawGrid() {
    QPen gridPen(QColor(230, 230, 230));

    for(int i = 0; i < width; i+=11) {
        addLine(i,0, i, height, gridPen);    // vertical line
    }

    for(int i = 0; i < height; i+=11) {
        addLine(0,i, width, i, gridPen);    // horizontal line
    }
}

MyScene::~MyScene()
{

}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *e) {
//void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e) {

    int rectX = floor(e->scenePos().x() / 11);  // rectangle number from lfet
    int rectY = floor(e->scenePos().y() / 11);  // rectangle number from top

    int index = (rectY*55 + rectX);     // index is a number of rectangle counting from 0 to 2199.

    if(rects[index].x() == -10) {   // so index does not exist (-10 is a default value)
        rects[index] = createDefaultRect(rectX, rectY); // add rect to vector
        addRect(rects[index], QPen(QColor(115, 115, 115)), QBrush(QColor(115, 115, 115))); // draw rectangle
    } else {

    }



//    QGraphicsItem *x;
//    QList<QGraphicsItem *> l;
//    l = this->items();
//    x = l.front();
//    //x->set
    qDebug() << rectX << rectY <<  index;// << l.size() << rects.size() << rects[1] << rects[1].x() << rects[1].y() ;

    //qDebug() << l.size() << x->isVisible() << x->pos().x() << x->scenePos().x();

}

// create a fectangle in indexX and indexY (these variables are numbers od rect from left and top)
QRect MyScene::createDefaultRect(int indexX, int indexY) {
    QRect r(indexX*11+1, indexY*11+1, 9, 9);
    return r;
}


// my clear function. Clear scene and put grid
void MyScene::clear() {
    QGraphicsScene::clear(); // clear scene
    rects.fill(QRect(-10, -10, 0, 0));  // clear vector with rectangles
    drawGrid(); // draw grid
}
