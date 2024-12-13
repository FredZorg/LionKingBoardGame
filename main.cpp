//Abey Saleh and Fred Zordgrager Group Project
#include <iostream>
#include <string>
#include <cstdlib>
#include "game.h"
#include "board.h"

using namespace std;

void startGame();
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

    board.addPlayers(player1, player2);

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
            if (entry == 1){
                player1 = game.lionSelectionMenu(player1);
                system("clear");
                entryValid = true;
                break;
            } else {
                system("clear");
                cout << "That was an invalid entry." << endl;
            }
        }

        entryValid = false;

        while (!entryValid) {
            cout << player2.getPlayerName() << " type 1 if you are ready to pick your lion." << endl;
            cin >> entry;
            if (entry == 1){
                player2 = game.lionSelectionMenu(player2);
                system("clear");
                entryValid = true;
                break;
            } else {
                system("clear");
                cout << "That was an invalid entry." << endl;
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
            if (entry == 1){
                player2 = game.lionSelectionMenu(player2);
                system("clear");
                entryValid = true;
                break;
            } else {
                system("clear");
                cout << "That was an invalid entry." << endl;
            }
        }

        entryValid = false;

        while (!entryValid) {
            cout << player1.getPlayerName() << " type 1 if you are ready to pick your lion." << endl;
            cin >> entry;
            if (entry == 1){
                player1 = game.lionSelectionMenu(player1);
                system("clear");
                entryValid = true;
                break;
            } else {
                system("clear");
                cout << "That was an invalid entry." << endl;
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

    while (!player1.getGameIsDone() && !player2.getGameIsDone()) {
        Game::GameState state;
        int index = game.getCurrentTurn() % 2;

        if ((index) == 0){
            cout << "\n" << (player1.getPlayerName()) << "'s Turn" << endl;
        } else {
            cout << "\n" << (player2.getPlayerName()) << "'s Turn" << endl;
        }


        if(index == 0){
            state = game.rollOrMenuInput(player1, board);
            player1 = state.player;
            board.setPlayer(0, player1); 
            board = state.board;
        } else {
            state = game.rollOrMenuInput(player2, board);
            player2 = state.player;
            board.setPlayer(1, player2); 
            board = state.board;
        }

        if (board.getTileColor(index, board.getPlayerPosition(index)) == 'B'){
            //nothing
        } else {
            game.setCurrentTurn(game.getCurrentTurn() + 1);
        }


        // Check for game end
        if (board.getPlayerPosition(0) > 51 || board.getPlayerPosition(1) > 51) {
            game.setIsNotDone(false);
        }
    }

    cout << "The game is done!!!" << endl;
    game.stupidSorting(player1);
    cout << endl;
    game.stupidSorting(player2);

    int strengthToPride = player1.getPridePoints();
    int wisdomToPride = player1.getWisdom();
    int staminaToPride = player1.getStamina();
    int total = strengthToPride + wisdomToPride + staminaToPride;
    total /= 100;
    int newPride1 = total * 1000;
    newPride1 += player1.getPridePoints();
    cout << player1.getPlayerName() << " TOTAL Pride Points: " << newPride1 << endl;

    strengthToPride = player2.getPridePoints();
    wisdomToPride = player2.getWisdom();
    staminaToPride = player2.getStamina();
    total = strengthToPride + wisdomToPride + staminaToPride;
    total /= 100;
    int newPride2 = total * 1000;
    newPride2 += player2.getPridePoints();
    cout << player2.getPlayerName() << " TOTAL Pride Points: " << newPride2 << endl;

    cout << endl << "The winner is ";

    if (newPride2 > newPride1){
        cout << player2.getPlayerName();
    } else if (newPride1 > newPride2){
        cout << player1.getPlayerName();
    } else {
        cout << "no one! It is a tie." << endl;
    }

    cout << ", congradulations! Thanks for playing!" << endl;

}

bool playerOneStarts(Player playerOne, Player playerTwo){
    int random = rand() % 2 + 1;
    int choice = 0;

    cout << "What is your choice?" << endl;
    cin >> choice;

    if ((choice != 1) && (choice != 2)){
        cout << "That is an invalid entry, please enter either 1 or 2." << endl;
        return playerOneStarts(playerOne, playerTwo);
    } else if (choice == random) {
        system("clear");
        cout << playerOne.getPlayerName() << " you get to go first!" << endl;

        return true;
    }
    system("clear");
    cout << playerTwo.getPlayerName() << " you get to go first!" << endl;

    return false;
}
