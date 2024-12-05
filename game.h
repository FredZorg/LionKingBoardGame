#ifndef GAME_H
#define GAME_H
#include <vector>
#include <iostream>

using namespace std;

class Game {
    public:
        //use the characters.txt file to replace the currentCharacters.txt file after the game is over
        void resetCharacters();
        //when a character is selected remove it from the currentCharacters.txt
        void removeSelectedCharacter();
        //display each character their stats and their ascii image
        void displayCharacter();
        //display ascii image for one animal
        void diskplayAscii();

    private:
        //vector holds the different ascii images for the lions
        vector<string> asciiLion;
        //vector holds the different ascii images for the mentors
        vector<string> asciiMentor;

};


#endif
