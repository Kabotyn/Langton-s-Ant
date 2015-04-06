#ifndef LANGTONANT_H
#define LANGTONANT_H

#include <vector>

enum directions { west, north, east, south }; // all possible ant directions
enum tileStatus { white, black };  // all possible field status

class LangtonAnt
{
public:
    LangtonAnt(int w, int h);   // number of fields in a row (w) and in col (h)
    ~LangtonAnt();

    void CCW(); // change direction Counter Clockwise
    void CW();  // change direction clockwise

    directions getDirection();  // return current ant direction

private:
    directions currentDirection;    // current ant direction
    std::vector<tileStatus> tiles;    // vector with all of fields (rect)

    int currentTile;   // index of current tile (where the ant is now)

    // dimension of whole field size
    int width;
    int height;

};

#endif // LANGTONANT_H
