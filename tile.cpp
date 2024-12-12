//Abey Saleh and Fred Zordgrager Group Project
#include "Tile.h"
#include "player.h"
#include "board.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>

Tile::Tile(){
    getRiddles();
}

//takes in the player and the tile color, based of the tile color it does different things
Player Tile::getMessage(Player player, int player_index){
        switch(color) {
            case 'U':  // Purple
                return isPurple(player);
            case 'G':  // Green
                return isGreen(player);
            default:   // Grey or Orange or any other color
                return player;
    }
    return player;
}

Player Tile::isPurple(Player player){
    string input;
    int random = rand() % riddlesAndAnswers[0].size();
    string answer = riddlesAndAnswers[1][random];

    cout << "You stumble across a scruffy old man. He asks you this riddle:" << endl;
    cout << riddlesAndAnswers[0][random] << endl;
    cout << "Input your answer" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, input);
    cout << "The answer is " << answer << endl;

    //get a random riddle and check their input
    if (answer == input) {
        cout << "He transforms into a wizard and applauds you for the correct answer. You are surrounded by a gust of wind and he disappears." << endl;
        cout << "You feel stronger:" << endl;
        cout << "500 Wisdom" << endl << "500 Strenght" << endl << "500 Stamina" << endl;
        player.addWisdom(500);
        player.addStrength(500);
        player.addStamina(500);
    } else {
        cout << "He walks away looking disappointed and nothing happens." << endl;
        cout << input << ", the correct answer was " << riddlesAndAnswers[1][random] << endl;
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
            cout << "You are both unlucky and lucky, isn't that kind of not sucky." << endl;
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
            cout << "Current Pride Points: " << player.getPridePoints() << endl;
        } else {
            if (advisorName == player.getAdvisorName()) {
                cout << "Congrats! You did not spin well, but your Advisor saved you.\n";
                cout << "You did not lose any Pride Points!\n";
                cout << "Current Pride Points: " << player.getPridePoints() << endl;
            } else {
                int lossPride = player.getPridePoints() + newPridePoints;
                player.setPridePoints(lossPride);
                cout << "Unfortunately, you did not spin well.\n";
                cout << "You lost " << newPridePoints << " Pride Points\n";
                cout << "Current Pride Points: " << player.getPridePoints() << endl;
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
