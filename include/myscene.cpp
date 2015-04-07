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

    rects.reserve(floor(width/11)*floor(height/11));
    rects.resize(floor(width/11)*floor(height/11));
    rects.fill(NULL);

    light = new QColor(255, 255, 255);
    dark = new QColor(115, 115, 115);


//    QImage image(":/image/ant.png");  // file with ant
//    antIcon = new QGraphicsPixmapItem(QPixmap::fromImage(image));
//    addItem(antIcon); // add icon to scene

//    antIcon->setPos(20, 20);
//    antCW();
//    antCW();


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

    int rectX = floor(e->scenePos().x() / 11);  // rectangle number from lfet
    int rectY = floor(e->scenePos().y() / 11);  // rectangle number from top

    int index = (rectY*floor(width/11) + rectX);     // index is a number of rectangle counting from 0 to 2199.

//qDebug() << "--" << index;
//qDebug() << "-"<< rects[index];

//changeTileColor(index);
    if(rects[index] != NULL)
        qDebug() << "  KLIK" << rects[index]->brush().color();
    else
        qDebug() << "  NIE ISTNIEJE";


//    if(rects[index] == NULL) {   // so index does not exist

//qDebug() << "++" << rects.size();

//        // create new object
//        QGraphicsRectItem *xx = new QGraphicsRectItem(rectX*11 + 1, rectY*11+1, 9, 9);
//        xx->setBrush(QBrush(*light));   // default color is white
//        xx->setPen(QPen(*light));

//        rects[index] = xx;

//        addItem(rects[index]);

//    } else {
//        if(rects[index]->brush().color() == *light) {
//            rects[index]->setBrush(QBrush(*dark));
//            rects[index]->setPen(QPen(*dark));
//        } else {
//            rects[index]->setBrush(QBrush(*light));
//            rects[index]->setPen(QPen(*light));
//        }
//    }

//qDebug() << rectX << rectY <<  index;

}

// create a fectangle in indexX and indexY (these variables are numbers od rect from left and top)
//QRect MyScene::createDefaultRect(int indexX, int indexY) {
//    QRect r(indexX*11+1, indexY*11+1, 9, 9);
//    return r;
//}


// my clear function. Clear scene and put grid
void MyScene::clear() {
    QGraphicsScene::clear(); // clear scene
    rects.fill(NULL);  // clear vector with rectangles
    drawGrid(); // draw grid
}

void MyScene::antCW() {
    antIcon->setRotation(antIcon->rotation() + 90);
}
void MyScene::antCCW() {
    antIcon->setRotation(antIcon->rotation() - 90);
}

void MyScene::changeTileColor(int index) {

    if(rects[index] == NULL) {   // so index does not exist

        int rectX = index % (width/11);
        int rectY = floor(index / (width/11));

// qDebug() << "INDEX" << index << width << rectX << rectY;

        // create new object
        QGraphicsRectItem *xx = new QGraphicsRectItem(rectX*11 + 1, rectY*11+1, 9, 9);
        xx->setBrush(QBrush(*light));   // default color is white
        xx->setPen(QPen(*light));

        rects[index] = xx;

        addItem(rects[index]);

    } else {
        if(rects[index]->brush().color() == *light) {
            rects[index]->setBrush(QBrush(*dark));
            rects[index]->setPen(QPen(*dark));
        } else {
            rects[index]->setBrush(QBrush(*light));
            rects[index]->setPen(QPen(*light));
        }
    }
}

bool MyScene::isTileHasColor(int index) {
    return (rects[index] != NULL);
}
