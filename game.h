//Abey Saleh and Fred Zordgrager Group Project
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include "player.h"
#include "board.h"

class Game {
    public:
        struct GameState {
            Player player;
            Board board;
            bool extraTurn = false;
        };
        
        Game(int start);
        void removeSelectedCharacter(int index);
        Player lionSelectionMenu(Player player);
        void displayStats(Player player);
        int roll();
        void playerNameInput(Player player);
        void createLionsVector();
        void creatAsciiLion();
        int getCurrentTurn();
        void setCurrentTurn(int turn);
        void displayAgeAndInfo(Player player);
        void displayGameStats(Player player);
        int prideOrTrain(Player player);
        GameState rollOrMenuInput(Player player, Board board);
        void displayMenu(Player player, Board board);
        void createAdvisorVector();
        Player advisorSelectionMenu (Player player);
        bool getIsNotDone();
        void setIsNotDone(bool thing);
        


    private:
        std::vector<Player> lions;
        std::vector<std::string> asciiLion;
        std::vector<std::string> advisorNames;
        std::vector<std::string> advisorAbilities;
        int currentTurn; //0 for player 1, 1 for player 2
        bool isNotDone;
};

#endif
