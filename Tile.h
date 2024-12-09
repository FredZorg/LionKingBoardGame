#ifndef TILE_H
#define TILE_H
#include <iostream>
#include "Player.cpp"

using namespace std;

class Tile {
    private:

    public:
        Tile();
        char color;
        Player getMessage(Player player);
};

#endif
