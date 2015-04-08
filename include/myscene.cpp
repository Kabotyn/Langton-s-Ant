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

    redRect = new QGraphicsRectItem(0, 0, 9, 9);
    redRect->setPen(QPen(Qt::red));
    addItem(redRect);

    light = new QColor(255, 255, 255);
    dark = new QColor(115, 115, 115);

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
    delete light;
    delete dark;
}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *e) {
// here will be possibility to change status(color) of tiles

//    int rectX = floor(e->scenePos().x() / 11);  // rectangle number from lfet
//    int rectY = floor(e->scenePos().y() / 11);  // rectangle number from top

//    int index = (rectY*floor(width/11) + rectX);     // index is a number of rectangle counting from 0 to 2199.


}

void MyScene::putRedRectInPos(int index) {

    int rectX = index % (width/11);
    int rectY = floor(index / (width/11));
    redRect->setPos( rectX*11+1, rectY*11+1 );
    redRect->setZValue(10);
}

// my clear function. Clear scene and put grid
void MyScene::clear() {

    for(int i = 0; i < rects.size(); i++ ) {
        if(rects[i] != NULL) {
            removeItem(rects[i]);
            rects[i] = NULL;
        }
    }

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

        // create new object
        QGraphicsRectItem *tempRectItem = new QGraphicsRectItem(rectX*11 + 1, rectY*11+1, 9, 9);
        tempRectItem->setBrush(QBrush(*light));   // default color is white
        tempRectItem->setPen(QPen(*light));

        rects[index] = tempRectItem;

        /* when item is added ones to the scene it is possible to change it properties
         * without adding it again and agian
        */
        addItem(rects[index]);

    } else {
        // code change tile color depend on current color
        if(rects[index]->brush().color() == *light) {
            rects[index]->setBrush(QBrush(*dark));
            rects[index]->setPen(QPen(*dark));
        } else {
            rects[index]->setBrush(QBrush(*light));
            rects[index]->setPen(QPen(*light));
        }
    }
}

// this function is usefull to visualise data on scene.
// return true if tile exists (ant was on this tile).
bool MyScene::isTileHasColor(int index) {
    return (rects[index] != NULL);
}
