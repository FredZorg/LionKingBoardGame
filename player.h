//Abey Saleh and Fred Zordgrager Group Project
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    private:
        std::string _playerName, _lionName, _advisorName, _advisorAbility, _lionAscii, _advisorAscii;
        int _strength, _stamina, _wisdom, _pride_points, _age, _choice, blueCounter, pinkCounter, brownCounter, purpleCounter, greenCounter, redCounter;
        bool gameIsDone, extraTurn;

    public:
        Player();
        Player(std::string playerName, std::string name, int pride_points, int strength, int stamina, int wisdom, std::string lionAscii, std::string advisorAscii);

        // getters
        std::string getPlayerName();
        std::string getLionName();
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPridePoints();
        int getAge();
        std::string getAdvisorName();
        std::string getAdvisorAbility();
        int getChoice();
        bool getGameIsDone();

        int getBlueOccurrences();
        int getPinkOccurrences();
        int getBrownOccurrences();
        int getPurpleOccurrences();
        int getGreenOccurrences();
        int getRedOccurrences();
        bool getExtraTurn();

        // setters
        void setExtraTurn(bool thing);
        void setAge(int age);
        void setPlayerName(std::string playerName);
        void setLionName(std::string name);
        void setStrength(int strength);
        void setStamina(int stamina);
        void setWisdom(int wisdom);
        void setPridePoints(int pride_points);
        void setAdvisorName(std::string name);
        void setAdvisorAbility(std::string advisorAbility);
        void setChoice(int choice);
        void setGameIsDone(bool duh);

        //adding
        void addStrength(int strength);
        void addStamina(int stamina);
        void addWisdom(int wisdom);
        void addPridePoints(int pride);
        void addGreenCounter(Player player);
        void addPurpleCounter(Player player);
        void addBrownCounter(Player player);
        void addPinkCounter(Player player);
        void addBlueCounter(Player player);
        void addRedCounter(Player player);
};

#endif
