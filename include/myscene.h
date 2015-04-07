#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QVector>

/* Thanks to this class I cad add mouseMoveEvent to scene
 */
class MyScene : public QGraphicsScene
{

public:
    explicit MyScene(QObject *parent = 0, int w = 500, int h = 400);
    ~MyScene();

    void clear();   // overload clear function. clear for me means no rects, only grid is show


private:
    QVector<QGraphicsRectItem *> rects;
    QRect createDefaultRect(int indexX, int indexY);
    void drawGrid();    // draw grid



    int width;  // width of scene
    int height; // height of scene

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);  // event when you press mouse button
};

#endif // MYSCENE_H
