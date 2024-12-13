//Abey Saleh and Fred Zordgrager Group Project
#include <iostream>
#include <string>
#include <cstdlib>
#include "game.h"
#include "board.h"

using namespace std;

void startGame();
void decideWinner(Player player1, Player player2);
bool playerOneStarts(Player playerOne, Player playerTwo);

int main(){
    srand(time(0));

    startGame();

    return 0;
}

void startGame(){
    Game game(0);
    Player player1;
    Player player2;
    Board board;
    string inputS;
    int trainOrCub1;
    int trainOrCub2;

    system("clear");

    //introduction
    cout << "Welcome to Ruler of the Pride! Your goal is to " << endl;
    cout << "pick a lion, and then go on a journey to grow " << endl;
    cout << "your stats and pride points until you eventually" << endl;
    cout << "reach pride rock where the lion with the best " << endl;
    cout << "stats and the most pride points wins." << endl << endl;

    //assign player names
    cout << "Before starting player one please enter your name." << endl;
    cin >> inputS;
    player1.setPlayerName(inputS);
    system("clear");

    cout << "Great! Player two please enter your name." << endl;
    cin >> inputS;
    player2.setPlayerName(inputS);
    system("clear");

    cout << "To pick the starting order "<< player1.getPlayerName() << " must pick either 1 or 2." << endl;
    if (playerOneStarts(player1, player2)){
        game.setCurrentTurn(0);
        //select lions
        bool entryValid = false;
        int entry = 0;

        while (!entryValid) {
            cout << player1.getPlayerName() << " type 1 if you are ready to pick your lion." << endl;
            cin >> entry;
            if (cin.fail()) { // Check if the input is invalid
                   cout << "That is an invalid input. Please input 1." << endl;
                   cin.clear(); // Clear the error flag
                   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input from buffer
               } else if (entry == 1) {
                   entryValid = true;
                   player1 = game.lionSelectionMenu(player1);
                   board.updatePlayer(0, player1);
                   system("clear");
               } else {
                   cout << "That is an invalid input. Please input 1." << endl;
               }
        }

        entryValid = false;

        while (!entryValid) {
            cout << player2.getPlayerName() << " type 1 if you are ready to pick your lion." << endl;
            cin >> entry;
            if (cin.fail()) { // Check if the input is invalid
                   cout << "That is an invalid input. Please input 1." << endl;
                   cin.clear(); // Clear the error flag
                   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input from buffer
               } else if (entry == 1) {
                   entryValid = true;
                   system("clear");
                   player2 = game.lionSelectionMenu(player2);
                   board.updatePlayer(1, player2);
               } else {
                   cout << "That is an invalid input. Please input 1." << endl;
               }
        }
    } else {
        game.setCurrentTurn(1);
        //select lions
        bool entryValid = false;
        int entry = 0;

        while (!entryValid) {
            cout << player2.getPlayerName() << " type 1 if you are ready to pick your lion." << endl;
            cin >> entry;
            if (cin.fail()) { // Check if the input is invalid
                   cout << "That is an invalid input. Please input 1." << endl;
                   cin.clear(); // Clear the error flag
                   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input from buffer
               } else if (entry == 1) {
                   entryValid = true;
                   player2 = game.lionSelectionMenu(player2);
                   board.updatePlayer(1, player2);
                   system("clear");
               } else {
                   cout << "That is an invalid input. Please input 1." << endl;
               }
        }

        entryValid = false;

        while (!entryValid) {
            cout << player1.getPlayerName() << " type 1 if you are ready to pick your lion." << endl;
            cin >> entry;
            if (cin.fail()) { // Check if the input is invalid
                   cout << "That is an invalid input. Please input 1." << endl;
                   cin.clear(); // Clear the error flag
                   cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input from buffer
               } else if (entry == 1) {
                   entryValid = true;
                   player1 = game.lionSelectionMenu(player1);
                   board.updatePlayer(0, player1);
                   system("clear");
               } else {
                   cout << "That is an invalid input. Please input 1." << endl;
               }
        }
    }



    trainOrCub1 = game.prideOrTrain(player1);
    if (trainOrCub1 == 0){
        player1 = game.advisorSelectionMenu(player1);
        player1.addPridePoints(-5000);
        player1.addWisdom(1000);
        player1.addStrength(500);
        player1.addStamina(500);
    } else {
        player1.addPridePoints(5000);
        player1.addWisdom(200);
        player1.addStrength(200);
        player1.addStamina(200);
    }
    player1.setChoice(trainOrCub1);
    trainOrCub2 = game.prideOrTrain(player2);
    if (trainOrCub2 == 0){
        player2 = game.advisorSelectionMenu(player2);
        player2.addPridePoints(-5000);
        player2.addWisdom(1000);
        player2.addStrength(500);
        player2.addStamina(500);
    } else {
        player2.addPridePoints(5000);
        player2.addWisdom(200);
        player2.addStrength(200);
        player2.addStamina(200);
    }
    player2.setChoice(trainOrCub2);

    board.initializeBoard(trainOrCub1, trainOrCub2);

    board.updatePlayer(0, player1);
    board.updatePlayer(1, player2);

    while (!player1.getGameIsDone() && !player2.getGameIsDone()) {
        Game::GameState state;
        int index = game.getCurrentTurn() % 2;

        if ((index) == 0){
            cout << "\n" << (player1.getPlayerName()) << "'s Turn" << endl;
        } else {
            cout << "\n" << (player2.getPlayerName()) << "'s Turn" << endl;
        }


        if(index == 0){
            player1.setExtraTurn(false);
            state = game.rollOrMenuInput(player1, board);
            player1 = state.player;
            board.setPlayer(0, player1);
            board = state.board;
        } else {
            player2.setExtraTurn(false);
            state = game.rollOrMenuInput(player2, board);
            player2 = state.player;
            board.setPlayer(1, player2);
            board = state.board;
        }

        game.setCurrentTurn(game.getCurrentTurn() + 1);



        // Check for game end
        if (board.getPlayerPosition(0) > 51 || board.getPlayerPosition(1) > 51) {
            game.setIsNotDone(false);
        }
    }
    
    decideWinner(player1, player2); 
    game.stupidSorting(player1);
    cout << endl;
    game.stupidSorting(player2);
    cout << endl;

    // cout << "The game is done!!!" << endl;
    // game.stupidSorting(player1);
    // cout << endl;
    // game.stupidSorting(player2);

    // int strengthToPride = player1.getPridePoints();
    // int wisdomToPride = player1.getWisdom();
    // int staminaToPride = player1.getStamina();
    // int total = strengthToPride + wisdomToPride + staminaToPride;
    // total /= 100;
    // int newPride1 = total * 1000;
    // newPride1 += player1.getPridePoints();
    // cout << player1.getPlayerName() << " TOTAL Pride Points: " << newPride1 << endl;

    // strengthToPride = player2.getPridePoints();
    // wisdomToPride = player2.getWisdom();
    // staminaToPride = player2.getStamina();
    // total = strengthToPride + wisdomToPride + staminaToPride;
    // total /= 100;
    // int newPride2 = total * 1000;
    // newPride2 += player2.getPridePoints();
    // cout << player2.getPlayerName() << " TOTAL Pride Points: " << newPride2 << endl;

    // cout << endl << "The winner is ";

    // if (newPride2 > newPride1){
    //     cout << player2.getPlayerName();
    // } else if (newPride1 > newPride2){
    //     cout << player1.getPlayerName();
    // } else {
    //     cout << "no one! It is a tie." << endl;
    // }

    // cout << ", congradulations! Thanks for playing!" << endl;

}

bool playerOneStarts(Player playerOne, Player playerTwo){
    int random = rand() % 2 + 1;
    int choice = 0;
    bool entryValid = false;

    while (!entryValid) {
        cout << "What is your choice?" << endl;
        cin >> choice;
        if (cin.fail()) { // Check if the input is invalid
               cout << "That is an invalid input. Please input 1." << endl;
               cin.clear(); // Clear the error flag
               cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input from buffer
        } else if ((choice != 1) && (choice != 2)) {
            system("clear");
            cout << "That is an invalid entry, please enter either 1 or 2." << endl;
            return playerOneStarts(playerOne, playerTwo);
        } else if (choice == random) {
            system("clear");
            cout << playerOne.getPlayerName() << " you get to go first!" << endl;
            return true;
        } else {
            system("clear");
            cout << playerTwo.getPlayerName() << " you get to go first!" << endl;
            return false;
        }
    }

    return false;
}

//Need to actually call this in start
void decideWinner(Player player1, Player player2) {
    int strengthToPride1 = player1.getPridePoints();
    int wisdomToPride1 = player1.getWisdom();
    int staminaToPride1 = player1.getStamina();
    int total1 = strengthToPride1 + wisdomToPride1 + staminaToPride1;
    total1 /= 100;
    int newPride1 = total1 * 1000;
    newPride1 += player1.getPridePoints();

    int strengthToPride2 = player2.getPridePoints();
    int wisdomToPride2 = player2.getWisdom();
    int staminaToPride2 = player2.getStamina();
    int total2 = strengthToPride2 + wisdomToPride2 + staminaToPride2;
    total2 /= 100;
    int newPride2 = total2 * 1000;
    newPride2 += player2.getPridePoints();

    if (newPride1 > newPride2) {
        cout << "Congratulations " << player1.getPlayerName() << " you won!\nYou are now the ALPHA";
    }
    else if (newPride1 < newPride2) {
        cout << "Congratulations " << player2.getPlayerName() << " you won!\nYou are now the ALPHA";
    }
    else {
        cout << "Wow. You guys have both demonstarted you are capable of being the ALPHA. \nEnjoy sharing the throne.";
    }

}
