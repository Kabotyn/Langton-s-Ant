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

    directions getDirection();  // return current ant direction

    int getCurrentTile(); // return current tile indexś

    tileColors getCurrentTileColor(); // return current tile color

    int countTileIndex(int p_posX, int p_posY); // count current tile index based on x and y, count from 0!!
    void countTilePosXY(int p_index, int &p_posX, int &p_posY); // count tile x and tile y from index

    // change color (from white to blac and from black to white) of tile in index in tiles (vector)
    void changeTileColor(int p_index);

    // make one step
    void move();

    // based on currentTile, currentDirection return index of next tile (where ant will be in next step)
    int nextTile();

    // set currentDirection to new walue base on status of tile number index
    void newDirection(int p_newTileIndex);

private:
    directions currentDirection;    // current ant direction
    std::vector<tileColors> tiles;    // vector with all of fields (rect)

    int currentTile;   // index of current tile (where the ant is now)

    // dimension of whole field size
    int width;
    int height;

};

#endif // LANGTONANT_H
