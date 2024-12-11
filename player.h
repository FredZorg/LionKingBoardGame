#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    private:
        std::string _playerName, _lionName, _advisorName, _advisorAbility, _lionAscii, _advisorAscii;
        int _strength, _stamina, _wisdom, _pride_points, _age, _choice;

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

        // setters
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

        //adding
        void addStrength(int strength);
        void addStamina(int stamina);
        void addWisdom(int wisdom);
};

#endif
