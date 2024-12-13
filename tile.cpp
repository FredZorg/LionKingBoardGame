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
    
    player.addPurpleCounter(player);

    cout << "You stumble across a scruffy old man. He asks you this riddle:" << endl;
    cout << riddlesAndAnswers[0][random] << endl;
    cout << "Input your answer" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    getline(cin, input);
    //get a random riddle and check their input
    if (answer.compare(input) == 1) { // why are we comparing a string to an int
        cout << "He transforms into a wizard and applauds you for the correct answer. You are surrounded by a gust of wind and he disappears." << endl;
        cout << "You feel stronger:" << endl;
        cout << "+500 Wisdom" << endl << "+500 Strength" << endl << "+500 Stamina" << endl;
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
    ifstream file_rand("random_events.txt");
    if (file_rand.fail()) {
        cout << "Error: Could not open random_events.txt" << endl;
        return player;
    }

    player.addGreenCounter(player);
    
    // Count valid lines
    vector<string> validEvents;
    string line;
    while (getline(file_rand, line)) {
        if (!line.empty()) {
            validEvents.push_back(line);
        }
    }
    
    if (validEvents.empty()) {
        cout << "Warning: No valid events found in random_events.txt" << endl;
        return player;
    }

    // Random chance to skip event
    if (rand() % 2 == 0) {
        cout << "You are both unlucky and lucky, isn't that kind of not sucky." << endl;
        return player;
    }

    // Select and process random event
    int randIndex = rand() % validEvents.size();
    string selectedEvent = validEvents[randIndex];

    // Parse the selected event
    size_t pos1 = selectedEvent.find('|');
    size_t pos2 = selectedEvent.find('|', pos1 + 1);
    size_t pos3 = selectedEvent.find('|', pos2 + 1);

    if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
        try {
            string desc = selectedEvent.substr(0, pos1);
            int trainOrPride = stoi(selectedEvent.substr(pos1 + 1, pos2 - pos1 - 1));
            int advisor = stoi(selectedEvent.substr(pos2 + 1, pos3 - pos2 - 1));
            int pridePoints = stoi(selectedEvent.substr(pos3 + 1));

            if (trainOrPride == player.getChoice()) {
                cout << desc << endl;
                
                if (pridePoints > 0) {
                    if (advisor > 0 && advisor <= 5 && player.getAdvisorName() == getAdvisorNameForNumber(advisor)) {
                        pridePoints *= 2;
                        cout << "Your advisor " << player.getAdvisorName() << " doubled your points!" << endl;
                    }
                    cout << "You gained " << pridePoints << " Pride Points!" << endl;
                    player.addPridePoints(pridePoints);
                } else {
                    if (advisor > 0 && advisor <= 5 && player.getAdvisorName() == getAdvisorNameForNumber(advisor)) {
                        cout << "Your advisor " << player.getAdvisorName() << " protected you from losing points!" << endl;
                    } else {
                        cout << "You lost " << -pridePoints << " Pride Points." << endl;
                        player.addPridePoints(pridePoints);
                    }
                }
            }
        } catch (const exception& e) {
            cout << "Error processing event: " << e.what() << endl;
        }
    }

    file_rand.close();
    return player;
}

string Tile::getAdvisorNameForNumber(int number) const {
    switch (number) {
        case 1: return "Rafiki";
        case 2: return "Nala";
        case 3: return "Sarabi";
        case 4: return "Zazu";
        case 5: return "Sarafina";
        default: return "";
    }
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
