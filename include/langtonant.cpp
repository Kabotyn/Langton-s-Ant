#include "langtonant.h"

LangtonAnt::LangtonAnt(int w, int h) {
    width = w;
    height = h;

    currentDirection = north;

    tiles.resize(width*height, white);
    tiles.reserve(width*height);

}

LangtonAnt::~LangtonAnt() {

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
