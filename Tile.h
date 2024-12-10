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
        Player getMessage(Player player, int player_index);
        Player isBlue(Player player);
        Player isRed(Player player, int player_input);
        Player isPink(Player player);
        Player isBrown(Player player);
        Player isPurple(Player player);
        Player isGreen(Player player);
};

#endif
