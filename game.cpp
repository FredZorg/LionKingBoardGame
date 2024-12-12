//Abey Saleh and Fred Zorgdrager
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include "game.h"

using namespace std;

Game::Game(int start){
    currentTurn = start;
    isNotDone = true;
    createLionsVector();
    createAdvisorVector();
    creatAsciiLion();
};

//when a character is selected remove it from the lions vector
void Game::removeSelectedCharacter(int index) {
    lions.erase(lions.begin() + index);
}
//display each character their stats and their ascii image and then prompt the user
Player Game::lionSelectionMenu(Player player) {
    int input;
    string line;
    bool invalid = true;
    for (int i = 0; i < lions.size(); i++) {
        cout << "Option # " << i+1 << endl;
        cout << "ENTER OPTION NUMBER CORRESPONDING TO THE CHARACTER YOU WANT TO CHOOSE" << endl;
        if (lions[i].getStrength() > lions[i].getStamina() && lions[i].getStrength() > lions[i].getWisdom()) {
            cout << lions[i].getLionName() << "'s best attribute is " << "their strength @ level: " << lions[i].getStrength() << endl;
            cout << "Their stamina is at level " << lions[i].getStamina() << ", ";
            cout << "and their wisdom is at level " << lions[i].getWisdom() << ".\n";
            cout << asciiLion[i] << endl;
            cout << line;
        }
        else if (lions[i].getStamina() > lions[i].getStrength() && lions[i].getStamina() > lions[i].getWisdom()) {
            cout << lions[i].getLionName() << "'s best attribute is " << "their stamina @ level: " << lions[i].getStamina() << endl;
            cout << "Their strength is at level "<< lions[i].getStrength() << ", ";
            cout << "and their wisdom is at level " << lions[i].getWisdom() << ".\n";
            cout << asciiLion[i] << endl;
            cout << line;
        }
        else if (lions[i].getWisdom() > lions[i].getStrength() && lions[i].getWisdom() > lions[i].getStamina()) {
            cout << lions[i].getLionName() << "'s best attribute is " << "their wisdom @ level: " << lions[i].getWisdom() << endl;
            cout << "Their strength is at level "<< lions[i].getStrength() << ", ";
            cout << "and their stamina is at level " << lions[i].getStamina() << ".\n";
            cout << asciiLion[i] << endl;
            cout << line;
        }
        else {
            cout << lions[i].getLionName();
            cout << "is "<< lions[i].getAge() << " years old, ";
            cout << "their strength is at level "<< lions[i].getStrength() << ", ";
            cout << "their stamina is at level " << lions[i].getStamina() << ", ";
            cout << "and their wisdom is at level " << lions[i].getWisdom() << ".\n";
            cout << asciiLion[i] << endl;
            cout << line;
        }
    }

    cout << "Enter the number you want as your lion." << endl;
    cin >> input;

    //check valid input
    while (invalid) {
        if (input < 1 || input > lions.size()) {
            cout << "That is an invalid entry, please select a lion." << endl;
            cin >> input;
        } else {
            invalid = false;
        }
    }

    player.setLionName(lions[input-1].getLionName());
    player.setStamina(lions[input-1].getStamina());
    player.setAge(lions[input-1].getAge());
    player.setWisdom(lions[input-1].getWisdom());
    player.setStrength(lions[input-1].getStrength());
    player.setPridePoints(lions[input-1].getPridePoints());
    lions.erase(lions.begin() + (input - 1));
    asciiLion.erase(asciiLion.begin() + (input - 1));

    return player;
}

int Game::getCurrentTurn(){
    return currentTurn;
}

void Game::setCurrentTurn(int turn){
    currentTurn = turn;
}

//could make this not hard coded
void Game::createAdvisorVector() {
    advisorNames.push_back("Rafiki");
    advisorNames.push_back("Nala");
    advisorNames.push_back("Sarabi");
    advisorNames.push_back("Zazu");
    advisorNames.push_back("Sarafina");
    advisorAbilities.push_back("Invisibility (the ability to become un-seen)");
    advisorAbilities.push_back("Night Vision (the ability to see clearly in darkness)");
    advisorAbilities.push_back("Energy Manipulation (the ability to shape and control the properties of energy)");
    advisorAbilities.push_back("Weather Control (the ability to influence and manipulate weather patterns)");
    advisorAbilities.push_back("Super Speed (the ability to run 4x faster than the maximum speed of lions)");
}

bool Game::getIsNotDone(){
    return isNotDone;
}
void Game::setIsNotDone(bool thing){
    isNotDone = thing;
}

Player Game::advisorSelectionMenu (Player player) {
    cout << "What advisor do you want to pick" << endl;
    int counter = 0;
    int input = 0;

    if (player.getAdvisorName() != "E"){
        cout << "(0)" << " - Keep current advisor" << endl;
    }

    for (int i = 0; i < advisorNames.size(); i++){
            cout << "(" << (i + 1) << ")" << advisorNames[i] << " - " << advisorAbilities[i] << endl;
        }
    cin >> input;

    if ((input == 0) && (player.getAdvisorName() != "E")){
        return player;
    }

    if ((input <= 0) || (input > counter)){
        cout << "That is an invalid input, please select again." << endl;
        advisorSelectionMenu(player);
    }

    if (player.getAdvisorName() == "E"){
        player.setAdvisorName(advisorNames[input -1]);
        player.setAdvisorAbility(advisorAbilities[input - 1]);
        advisorNames.erase(advisorNames.begin() + (input - 1));
        advisorAbilities.erase(advisorAbilities.begin() + (input - 1));
    } else {
        string tempN = player.getAdvisorName();
        string tempA = player.getAdvisorAbility();
        player.setAdvisorName(advisorNames[input -1]);
        player.setAdvisorAbility(advisorAbilities[input - 1]);
        advisorNames.erase(advisorNames.begin() + (input - 1));
        advisorAbilities.erase(advisorAbilities.begin() + (input - 1));
        advisorNames.push_back(tempN);
        advisorAbilities.push_back(tempA);
    }

    return player;
}

    //displays the specific characters character and its stats
void Game::displayAgeAndInfo(Player player) {
    system("clear");
    cout << endl << "Here are your players' name and age:" << endl;
    cout << "Selected Lion Name: " << player.getLionName() << endl;
    cout << "Age: " << player.getAge() << endl;
}
void Game::displayGameStats(Player player) {
    system("clear");
    cout << endl << "Here are your players' game stats:" << endl;
    cout << "Selected Lion Name: " << player.getLionName() << endl;
    cout << "Strength: " << player.getStrength() << endl;
    cout << "Stamina: " << player.getStamina() << endl;
    cout << "Wisdom: " << player.getWisdom() << endl;
}
    //have them pick to the pride lands or to cub training, ture if pride lands false if cub training
int Game::prideOrTrain(Player player) {
    int answer;
    cout << player.getPlayerName() << " you have picked your character. Now, the game begins." << endl;
    cout << "Do you want to go to Cub Training to hone in on your " << endl;
    cout << "skills, or are you confident enough to go staight to" << endl;
    cout << "the Pride Lands?\n Pick Wisely!!" << endl;;
    cout << "Enter 0 if you would like to go to Cub Training first!" << endl;
    cout << "Enter 1 if you would like to go to the Pride Lands first!" << endl;
    cin >> answer;
    if (answer == 0) {
        system("clear");
        return 0;
    } else if (answer == 1) {
        system("clear");
        return 1;
    } else {
        system("clear");
        cout << "You must enter a valid input\n";
        prideOrTrain(player);
    }
    return 0;
}

//choose whether to roll or go to the menu
Game::GameState Game::rollOrMenuInput(Player player, Board board) {
    GameState state;
    state.extraTurn = false;
    string input;
    string lowerInput;
    cout << endl << "Would you like to roll your dice, or go to the Menu?\nFor menu, type: \"menu\"\nFor dice, type \"dice\"" << endl;
    cin >> input;

    for(int i = 0; i < input.length(); i++) {
        lowerInput += tolower(input[i]);
    }

    if (lowerInput == "dice") {
        int rollResults = roll();
        cout << "You rolled a " << rollResults << "!" << endl;

        int playerIndex = (getCurrentTurn() % 2);
        player = board.movePlayer(playerIndex, rollResults);

        board.displayBoard();

        // Check if landed on blue tile and set flag in GameState
        if (board.getTileColor(playerIndex, board.getPlayerPosition(playerIndex)) == 'B') {
            cout << "Extra turn granted!" << endl;
            state.extraTurn = true;  // Add this flag to GameState struct
        } else {
            state.extraTurn = false;
        }
    } else if (lowerInput == "menu") {
        displayMenu(player, board);
        return rollOrMenuInput(player, board);
    } else {
        string stupid;
        cout << "Invalid input - press enter to make a VALID decision";
        cin >> stupid;
        return rollOrMenuInput(player, board);
    }

    state.player = player;
    state.board = board;

    return state;
}
//rolls a number between one and six
// should call func that actualy moves pieces and change this to void
int Game::roll() {
    int rollValue = rand() % (6) + 1;
    return rollValue;
}

void Game::createLionsVector() {
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

void Game::displayMenu(Player player, Board board) {
    int menu;

    system("clear");
    cout << "This is your menu. Enter the number corresponding to select what you would like to do!\n";
    cout << "1. Review your player: Check on your health and age!\n";
    cout << "2. Review your player: Check on your stamina, strength, wisdom, and pride points!\n";
    cout << "3. Review your Advisor: Check on your Advisor's name and special ability!\n";
    cout << "4. Review your Position: Check where you are on the board!\n";
    cout << "5. Review your progress: See your TOTAL Pride Points if the game ended right now. " << endl;
    cout << "6. Go Back." << endl;
    cin >> menu;
    system("clear");

    if (menu == 1) {
        displayAgeAndInfo(player);
    } else if (menu == 2) {
        displayGameStats(player);
    } else if (menu == 3) {
        if (player.getAdvisorName() == "E"){
            cout << "You do not have an advisor yet." << endl;
        } else {
            cout << "Your advisors name is " << player.getAdvisorName() << "." << endl;
            cout << "Special Ability: " << endl << "- " << player.getAdvisorAbility() << endl;
        }

    } else if (menu == 4) {
        board.displayBoard();
    } else if (menu == 5) {
        int strengthToPride = player.getPridePoints();
        int wisdomToPride = player.getWisdom();
        int staminaToPride = player.getStamina();
        int total = strengthToPride + wisdomToPride + staminaToPride;
        total /= 100;
        int newPride = total * 1000;
        newPride += player.getPridePoints();
        cout << "Your TOTAL Pride Points: " << newPride << endl;
    } else if (menu == 6){

    } else {
        cout << "Invalid menu option.\n";
        displayMenu(player, board);
    }
}

    //creat the asciiLion vector using the asciiLions.cpp
void Game::creatAsciiLion(){
    fstream file;
    string junk;
    file.open("asciiLion.txt");

    string ascii;

    if (file.fail()) {
        cout << "Error opening ascii file" << endl;
        return;
    }

    for (int i = 0; i < lions.size(); i ++){
        getline(file, ascii, 'Z');
        getline(file, junk);
        asciiLion.push_back(ascii);
    }

    file.close();
}
