#ifndef MYSCENE_H
#define MYSCENE_H


#include <QGraphicsScene>
#include <QVector>
#include <QObject>

/* Thanks to this class I cad add mouseMoveEvent to scene
 */
class MyScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit MyScene(int w = 500, int h = 400);
    ~MyScene();

    void clear();   // overload clear function. clear for me means no rects, only grid is show

    // rotate ant icon in cw or ccw
    void antCW();
    void antCCW();

    // change tile color. If tile is NULL, change it to white, if it is white changge to black and from black change to white
    void changeTileColor(int index);

    bool isTileHasColor(int index); // true if yes, false if not (means that ant was on this tile)

    // change current ant tile border to current position
    void putRedRectInPos(int index);

signals:
    void mouseClickOnTile(int index);

private:
    QVector<QGraphicsRectItem *> rects;
    QGraphicsRectItem *redRect; // rectangle with ant
    void drawGrid();    // draw grid

    QColor *light;  // white color tile
    QColor *dark;   // dark(black) color tile

    int width;  // width of scene
    int height; // height of scene

    QGraphicsPixmapItem* antIcon; // item with Ant icon (png file from reosurces)

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);  // event when you press mouse button
};

#endif // MYSCENE_H
