#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include "player.h"

class Game {
    public:
        Game(int start);
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
        int getCurrentTurn();
        void setCurrentTurn();
        void displayAgeAndInfo(Player player);
        void displayGameStats(Player player);
        int prideOrTrain(Player player);
        void rollOrMenuInput(Player player);
        void displayMenu();
        void createAdvisorVector();
        Player advisorSelectionMenu (Player player);


    private:
        std::vector<std::string> asciiLion;
        std::vector<std::string> asciiAdvisor;
        std::vector<std::string> advisorNames;
        std::vector<std::string> advisorAbilities;
        int currentTurn; //0 for player 1, 1 for player 2
};

#endif
