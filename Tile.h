//Abey Saleh and Fred Zordgrager Group Project
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
        Player isPurple(Player player);
        Player isGreen(Player player);
        string getAdvisorNameForNumber(int number) const;
};

#endif
