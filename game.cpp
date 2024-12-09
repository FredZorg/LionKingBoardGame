#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include "player.cpp"

using namespace std;

class Game {
    public:
        Game(){
            cout << "it worked" << endl;
        };
        //when a character is selected remove it from the lions vector
        void removeSelectedCharacter(int index) {
            lions.erase(lions.begin() + index);
        }
        //display each character their stats and their ascii image and then prompt the user
        Player lionSelectionMenu(Player player) {
            string name;
            cout << "Enter your name";
            cin >> name;
            int input;
            fstream file_asc;
            file_asc.open("asciiLion.txt");
            if (file_asc.fail()) {
                cout << "File did not open.";
                return player;
            }
            string line;
            for (int i = 0; i < lions.size(); i++) {
                cout << "Option # " << i+1 << endl;
                cout << "ENTER OPTION NUMBER CORRESPONDING TO THE CHARACTER YOU WANT TO CHOOSE";
                if (lions[i].getStrength() > lions[i].getStamina() && lions[i].getStrength() > lions[i].getWisdom()) {
                    cout << lions[i].getLionName() << "'s best attribute is " << "their strength @ level: " << lions[i].getStrength() << endl;
                    cout << "Their stamina is at level " << lions[i].getStamina() << ", ";
                    cout << "and their wisdom is at level " << lions[i].getWisdom() << ".\n";
                    getline(file_asc, line, 'Z');
                    cout << line;
                }
                else if (lions[i].getStamina() > lions[i].getStrength() && lions[i].getStamina() > lions[i].getWisdom()) {
                    cout << lions[i].getLionName() << "'s best attribute is " << "their stamina @ level: " << lions[i].getStamina() << endl;
                    cout << "Their strength is at level "<< lions[i].getStrength() << ", ";
                    cout << "and their wisdom is at level " << lions[i].getWisdom() << ".\n";
                    getline(file_asc, line, 'Z');
                    cout << line;

                }
                else if (lions[i].getWisdom() > lions[i].getStrength() && lions[i].getWisdom() > lions[i].getStamina()) {
                    cout << lions[i].getLionName() << "'s best attribute is " << "their wisdom @ level: " << lions[i].getWisdom() << endl;
                    cout << "Their strength is at level "<< lions[i].getStrength() << ", ";
                    cout << "and their stamina is at level " << lions[i].getStamina() << ".\n";
                    getline(file_asc, line, 'Z');
                    cout << line;
                }
                else {
                    cout << lions[i].getLionName();
                    cout << "is "<< lions[i].getAge() << " years old, ";
                    cout << "their strength is at level "<< lions[i].getStrength() << ", ";
                    cout << "their stamina is at level " << lions[i].getStamina() << ", ";
                    cout << "and their wisdom is at level " << lions[i].getWisdom() << ".\n";
                    getline(file_asc, line, 'Z');
                    cout << line;
                }
            }
            string line2;
            getline(file_asc, line2);
            cout << line2;
            file_asc.close();

            cin >> input;
            player.setPlayerName(name);
            player.setLionName(lions[input-1].getLionName());
            player.setStamina(lions[input-1].getStamina());
            player.setAge(lions[input-1].getAge());
            player.setWisdom(lions[input-1].getWisdom());
            player.setStrength(lions[input-1].getStrength());
            player.setPridePoints(lions[input-1].getPridePoints());

            return player;

            // removeSelectedCharacter(input-1);
        }
        //displays the specific characters character and its stats
        void displayAgeAndInfo(Player player) {
            cout << "\nHere are your players' name and age:\n" << endl;
            cout << "Selected Lion Name: " << player.getLionName() << endl;
            cout << "Age: " << player.getAge() << endl;
        }
        void displayGameStats(Player player) {
            cout << "\nHere are your players' game stats:\n" << endl;
            cout << "Selected Lion Name: " << player.getLionName() << endl;
            cout << "Strength: " << player.getStrength() << endl;
            cout << "Stamina: " << player.getStamina() << endl;
            cout << "Wisdom: " << player.getWisdom() << endl;
        }
        //have them pick to the pride lands or to cub training, ture if pride lands false if cub training
        int prideOrTrain() {
            int answer;
            cout << "You have picked your character. Now, the game begins.\nDo you want to go to Cub Training to hone in on your skills, or are you confident enough to go staight to the Pride Lands?\n Pick Wisely!!";
            cout << "Enter 0 if you would like to go to Cub Training first!\n";
            cout << "Enter 1 if you would like to go to the Pride Lands first!";
            cin >> answer;
            if (answer == 0) return answer;
            if (answer == 1) return answer;
            else cout << "You must enter a valid input";
            prideOrTrain();
        }
        //choose whether to roll or go to the menu
        void rollOrMenuInput() {
            string input;
            string lowerInput;
            cout << "Would you like to roll your dice, or go to the Menu?\nFor menu, type: \"menu\"\n For dice, type \"dice\"";
            cin >> input;
            for(int i = 0; i < input.length(); i++) {
                    lowerInput += tolower(input[i]);
                }
            if (lowerInput == "dice") {
                roll();
            }
            if (lowerInput == "menu") {
                displayMenu();
            }
            else {
                string stupid;
                cout << "Invalid input - press enter to make a VALID decision";
                cin >> stupid;
                rollOrMenuInput();

            }
        }
        //rolls a number between one and six
        // should call func that actualy moves pieces and change this to void
        void roll() {
            int rollValue = rand() % (6) + 1;
        }
        void createLionsVector() {
            int count = 0;
            fstream file_input;
            file_input.open("characters.txt");
            if (file_input.fail()) {
                cout << "File did not open.";
                return;
            }
            string line;
            while (getline(file_input, line)) {
                count++;
            }
            file_input.clear();
            file_input.seekg(0);
            for (int i = 0; i < count; i++) {
                Player newPlayer; // Create a new Player object for each lion

                string line2;
                for (int j = 0; j < 5; j++) {
                    getline(file_input, line2, '|'); // Read delimited data
                    if (j == 0) newPlayer.setLionName(line2);
                    if (j == 1) newPlayer.setAge(stoi(line2));
                    if (j == 2) newPlayer.setStrength(stoi(line2));
                    if (j == 3) newPlayer.setStamina(stoi(line2));
                    if (j == 4) newPlayer.setWisdom(stoi(line2));
                }
                string line3;
                getline(file_input, line3); // Read PridePoints
                newPlayer.setPridePoints(stoi(line3));

                lions.push_back(newPlayer); // Add the player to the lions vector
            }

            file_input.close(); // Close the file
            }

        //creat the asciiLion vector using the asciiLions.cpp
        void creatAsciiLion();
        //creat the asciiLion vector using the asciiAdvisor.cpp
        void creatAsciiAdvisor();
        vector<Player> lions;

    private:
        //vector holds the different ascii images for the lions
        vector<string> asciiLion;
        //vector holds the different ascii images for the mentors
        vector<string> asciiAdvisor;
        //vector hold the different lions and their stats
        void displayMenu(Player player) {
            int menu;
            cout << "This is your menu. Enter the number corresponding to what you would like to do!\n";
            cout << "1. Review your player: Check on your health and age!\n";
            cout << "2. Review your player: Check on your stamina, strength, wisdom, and pride points!\n";
            cout << "3. Review your Advisor: Check where you are on the board!\n";
            cout << "4. Review your Position: Check where you are on the board!\n";
            cout << "5. Review your progress: Restart if you are not happy with decisons that YOU have made.\n";
            cin >> menu;
            if (answer == 0) return answer;

            if (menu == 1)


            cout << "2. Review your Advisor: Check who your current advisor is on the game.\n";
            cout << "3. "
        }

};
