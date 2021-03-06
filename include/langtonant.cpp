#include "langtonant.h"

LangtonAnt::LangtonAnt(int p_w, int p_h) {
    width = p_w;
    height = p_h;

    currentDirection = north;

    tiles.resize(width*height, white);
    tiles.reserve(width*height);

    // init curent tile more or less in the middle of space
    currentTile = countTileIndex(floor(width/2), floor(height/2));

}

LangtonAnt::~LangtonAnt() {

}

void LangtonAnt::restart() {
    currentDirection = north;

    tiles.clear();
    tiles.resize(width*height, white);

    // init curent tile more or less in the middle of space
    currentTile = countTileIndex(floor(width/2), floor(height/2));
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


int LangtonAnt::getCurrentTile() {
    return currentTile;
}

tileColors LangtonAnt::getCurrentTileColor() {
    return tiles[currentTile];
}

// change direction counter clockwise (right)
void LangtonAnt::CCW() {
    switch (currentDirection) {
    case west:
        currentDirection = south;
        break;
    case south:
        currentDirection = east;
        break;
    case east:
        currentDirection = north;
        break;
    case north:
        currentDirection = west;
        break;
    }
}

// change direction clockwise (left)
void LangtonAnt::CW() {
    switch (currentDirection) {
    case west:
        currentDirection = north;
        break;
    case south:
        currentDirection = west;
        break;
    case east:
        currentDirection = south;
        break;
    case north:
        currentDirection = east;
        break;
    }
}


void LangtonAnt::changeTileColor(int p_index) {
    tiles[p_index] = (tiles[p_index] == white) ? black : white;
}



void LangtonAnt::onMouseChaneTile(int index) {
    changeTileColor(index);
}

int LangtonAnt::nextTile() {
    int currentX, currentY; // x and y of current tile
    countTilePosXY(currentTile, currentX, currentY);
    int newX, newY; // position of next tile (x, y)

    switch(currentDirection) {
    case west:
        newX = (currentX == 0) ? (width - 1) : (currentX - 1);
        newY = currentY;
        break;
    case north:
        newX = currentX;
        newY = (currentY == 0) ? (height - 1) : (currentY - 1);
        break;
    case east:
        newX = (currentX == (width - 1)) ? 0 : (currentX + 1);
        newY = currentY;
        break;
    case south:
        newX = currentX;
        newY = (currentY == (height - 1)) ? 0 : (currentY + 1);
        break;
    }

    return countTileIndex(newX, newY);

}

void LangtonAnt::newDirection(int p_newTileIndex) {
    if(tiles[p_newTileIndex] == white)
        CW();
    else
        CCW();
}

void LangtonAnt::move() {
    changeTileColor(currentTile);
    currentTile = nextTile();
    newDirection(currentTile);
}
