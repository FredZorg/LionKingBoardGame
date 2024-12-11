#include "tile.h"
#include "player.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iostream>

//takes in the player and the tile color, based of the tile color it does different things
Player Tile::getMessage(Player player, int player_index){


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

//Normal tile, need to use random.txt for events, for some events an advisor will negate a negative task
//cout each event and update each player thing 
Player Tile::isGreen(Player player) {
    fstream file_rand;
    file_rand.open("random_events.txt");
    if (file_rand.fail()) {
        cout << "File did not open.";
        return player;
    }

    string line;
    int lines = 0;

    // Count the number of lines
    while (getline(file_rand, line)) {
        lines++;
    }
    file_rand.clear();      // Clear EOF and error flags
    file_rand.seekg(0);     // Reset file pointer to beginning

    // Loop to handle "restart" behavior
    while (true) {
        int randy = rand() % 2 + 1;
        if (randy == 1) {
            return player;
        }

        string desc, trainOrPride, advisor, pridePoints;
        int ranVent = rand() % lines + 1;

        // Read the random event
        for (int i = 0; i < ranVent; i++) {
            getline(file_rand, desc, '|');
            getline(file_rand, trainOrPride, '|');
            getline(file_rand, advisor, '|');
            getline(file_rand, pridePoints);
        }

        int newTrainOrPride = stoi(trainOrPride);
        int newAdvisor = stoi(advisor);
        int newPridePoints = stoi(pridePoints);
        string advisorName;

        // Map newAdvisor values to advisor names
        if (newAdvisor == 0) advisorName = "none";
        else if (newAdvisor == 1) advisorName = "Rafiki";
        else if (newAdvisor == 2) advisorName = "Nala";
        else if (newAdvisor == 3) advisorName = "Surabi";
        else if (newAdvisor == 4) advisorName = "Zazu";
        else if (newAdvisor == 5) advisorName = "Sarafina";

        // If the player's choice doesn't match, restart the loop
        if (newTrainOrPride != player.getChoice()) {   
            continue;
        }

        // Otherwise, process the result and exit the loop
        if (newPridePoints > 0) {
            int morePride = player.getPridePoints() + newPridePoints;
            player.setPridePoints(morePride);
            cout << desc << endl;
            cout << "Congrats! You spun well. Enjoy " << newPridePoints << " more Pride Points\n";
            cout << "Current Pride Points: " << player.getPridePoints();
        } else {
            if (advisorName == player.getAdvisorName()) {
                cout << "Congrats! You did not spin well, but your Advisor saved you.\n";
                cout << "You did not lose any Pride Points!\n";
                cout << "Current Pride Points: " << player.getPridePoints();
            } else {
                int lossPride = player.getPridePoints() + newPridePoints;
                player.setPridePoints(lossPride);
                cout << "Unfortunately, you did not spin well.\n";
                cout << "You lost " << newPridePoints << " Pride Points\n";
                cout << "Current Pride Points: " << player.getPridePoints();
            }
        }

        break; // Exit the loop after processing the result
    }

    file_rand.close();
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
