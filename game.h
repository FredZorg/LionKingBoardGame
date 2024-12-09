#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include "player.h"

class Game {
    public:
        Game();
        void removeSelectedCharacter(int index);
        Player lionSelectionMenu(Player player);
        void displayStats(Player player);
        int prideOrTrain();
        void rollOrMenuInput();
        int roll();
        void playerNameInput(Player player);
        void createLionsVector();
        void creatAsciiLion();
        void creatAsciiAdvisor();
        std::vector<Player> lions;

    private:
        std::vector<std::string> asciiLion;
        std::vector<std::string> asciiAdvisor;
        void displayMenu();
};

#endif
