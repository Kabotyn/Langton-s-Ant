#ifndef LANGTONANT_H
#define LANGTONANT_H

#include <vector>
#include <cmath>
#include <QDebug>

enum directions { west, north, east, south }; // all possible ant directions
enum tileColors { white, black };  // all possible field status

class LangtonAnt
{
public:
    LangtonAnt(int p_w, int p_h);   // number of fields in a row (w) and in col (h)
    ~LangtonAnt();

    void CCW(); // change direction Counter Clockwise
    void CW();  // change direction clockwise

    int getCurrentTile(); // return current tile indexś

    tileColors getCurrentTileColor(); // return current tile color

    // make one step
    void move();

    void restart(); // restart object to init time


    // change color (from white to blac and from black to white) of tile in index in tiles (vector)
    void changeTileColor(int p_index);

private:
    directions currentDirection;    // current ant direction
    std::vector<tileColors> tiles;    // vector with all of fields (rect)

    int currentTile;   // index of current tile (where the ant is now)

    // dimension of whole field size
    int width;
    int height;

    // based on currentTile, currentDirection return index of next tile (where ant will be in next step)
    int nextTile();

    // set currentDirection to new walue base on status of tile number index
    void newDirection(int p_newTileIndex);



    // count current tile index based on x and y, count from 0!!
    int countTileIndex(int p_posX, int p_posY);

    // count tile x and tile y from index
    void countTilePosXY(int p_index, int &p_posX, int &p_posY);


};

#endif // LANGTONANT_H
