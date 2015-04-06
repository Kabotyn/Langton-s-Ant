#include "langtonant.h"

LangtonAnt::LangtonAnt(int p_w, int p_h) {
    width = p_w;
    height = p_h;

    currentDirection = north;

    tiles.resize(width*height, white);
    tiles.reserve(width*height);

}

LangtonAnt::~LangtonAnt() {

}

// count tail index number start from 0
int LangtonAnt::countTileIndex(int p_posX, int p_posY) {
    return (p_posY * width) + p_posX;
}

// count x and y from index number
void LangtonAnt::countTilePosXY(int p_index, int &p_posX, int &p_posY) {
    p_posX = p_index % width;
    p_posY = floor(p_index/width);
}

directions LangtonAnt::getDirection() {
    return currentDirection;
}

void LangtonAnt::CCW() {
    if(getDirection() == west)
        currentDirection = south;
    else
        currentDirection--;
}

void LangtonAnt::CW() {
    if(getDirection() == south)
        currentDirection = west;
    else
        currentDirection++;
}
