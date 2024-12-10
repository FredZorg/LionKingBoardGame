#include "tile.h"
#include "player.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

//takes in the player and the tile color, based of the tile color it does different things
Player Tile::getMessage(Player player, int player_input){


    return player;
}

Player Tile::isBlue(Player player){
    cout << "You’ve found a beautiful oasis! Enjoy!" << endl;
    cout << "+200 Wisdom" << endl << "+200 Strenght" << endl << "+200 Stamina" << endl;
    player.addWisdom(200);
    player.addStrength(200);
    player.addStamina(200);
    return player;
}

Player Tile::isRed(Player player, int player_input){
    cout << "Uh-oh, you’ve stumbled into the Graveyard! You take a hit to your stats." << endl;
    cout << "-100 Wisdom" << endl << "-100 Strenght" << endl << "-100 Stamina" << endl << "-10 tiles" << endl;
    player.addWisdom(-100);
    player.addStrength(-100);
    player.addStamina(-100);

    return player;

}

Player Tile::isPink(Player player){
    cout << "Welcome to the land of enrichment! Enjoy this boost to your stats!" << endl;
    cout << "+300 Wisdom" << endl << "+300 Strenght" << endl << "+300 Stamina" << endl;
    cout << "You also get to swap/pick an advisor" << endl;
    player.addWisdom(300);
    player.addStrength(300);
    player.addStamina(300);

    return player;
}

Player Tile::isBrown(Player player, int dist){
    cout << "You got caught by Hyenas! You are severely weakend." << endl;
    cout << "-300 Wisdom" << endl << "-300 Strenght" << endl << "-300 Stamina" << endl;
    cout << "Move back to your last tile." << endl;
    player.addWisdom(-300);
    player.addStrength(-300);
    player.addStamina(-300);

    return player;
}

Player Tile::isPurple(Player player){
    string input;
    int random = rand() % riddlesAndAnswers[0].size();

    cout << "You stumble across a scruffy old man. He asks you this riddle:" << endl;
    cout << riddlesAndAnswers[0][random] << endl;
    cin >> input;



    //get a random riddle and check their input
    if (riddlesAndAnswers[0][random] == input) {
        cout << "He transforms into a wizard and applauds you for the correct answer. You are surrounded by a gust of wind and he disappears." << endl;
        cout << "You feel stronger:" << endl;
        cout << "500 Wisdom" << endl << "500 Strenght" << endl << "500 Stamina" << endl;
        player.addWisdom(500);
        player.addStrength(500);
        player.addStamina(500);
    } else {
        cout << "He walks away looking disapointed and nothing happens." << endl;
    }

    return player;
}

Player Tile::isGreen(Player player){

    return player;
}

void Tile::getRiddles(){
    ifstream file("riddles.txt");
        string riddle = " ", answer = " ";
        if (file.fail()) {
            cout << "Failed to open riddles file" << endl;
            return;
        }

        vector<string> riddles;
        vector<string> answers;

        while (getline(file, riddle, '|')) {
            getline(file, answer);  // gets rest of line after '|'
            riddles.push_back(riddle);
            answers.push_back(answer);
        }
        riddlesAndAnswers.push_back(riddles);
        riddlesAndAnswers.push_back(answers);

        file.close();
}
