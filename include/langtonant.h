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

    int countTileIndex(int p_posX, int p_posY); // count current tile index based on x and y, count from 0!!
    void countTilePosXY(int p_index, int &p_posX, int &p_posY);

private:
    directions currentDirection;    // current ant direction
    std::vector<tileColors> tiles;    // vector with all of fields (rect)

    int currentTile;   // index of current tile (where the ant is now)

    // dimension of whole field size
    int width;
    int height;

};

#endif // LANGTONANT_H
