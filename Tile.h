#ifndef TILE_H
#define TILE_H

#include <string>
#include <iostream>
#include <vector>
#include "player.h"

using namespace std;

class Tile {
    private:
        vector<vector<string> > riddlesAndAnswers;

    public:
        Tile();
        char color;
        void getRiddles();
        Player getMessage(Player player, int player_index);
        Player isBlue(Player player);
        Player isRed(Player player, int player_input);
        Player isPink(Player player);
        Player isBrown(Player player, int dist);
        Player isPurple(Player player);
        Player isGreen(Player player);
};

#endif
