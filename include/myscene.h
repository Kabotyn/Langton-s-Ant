#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>

/* Thanks to this class I cad add mouseMoveEvent to scene
 */
class MyScene : public QGraphicsScene
{

public:
    explicit MyScene(QObject *parent = 0, int w = 500, int h = 400);
    ~MyScene();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
};

#endif // MYSCENE_H
