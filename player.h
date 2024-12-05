#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

using namespace std;

class Player{
    public:
        //constructor if their is no name given, will not happen
        Player() {
            pridePoints = 100;
            stamina = 100;
            wisdom = 100;
        }

        //cunstructor which takes in the lions name and stats
        Player(int pride, int stam, int wis, string lion) {
            pridePoints = pride;
            stamina = stam;
            wisdom = wis;
            lionName = lion;
        }


    private:
        string playerName;
        string lionName;
        string advisorName;
        int pridePoints;
        int stamina;
        int wisdom;


};




#endif
