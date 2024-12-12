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
    } else {
        game.setCurrentTurn(1);
    }

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

    trainOrCub1 = game.prideOrTrain(player1);
    player1.setChoice(trainOrCub1);
    trainOrCub2 = game.prideOrTrain(player2);
    player2.setChoice(trainOrCub2);

    board.initializeBoard(trainOrCub1, trainOrCub2);

    while (game.getIsNotDone()) {
        Game::GameState state;

        cout << "\nPlayer " << (game.getCurrentTurn() % 2 + 1) << "'s Turn" << endl;

        if(game.getCurrentTurn() % 2 == 0){
            state = game.rollOrMenuInput(player1, board);
            player1 = state.player;
            board = state.board;
        } else {
            state = game.rollOrMenuInput(player2, board);
            player2 = state.player;
            board = state.board;
        }

        // Only increment turn if no extra turn was granted
        if (!state.extraTurn) {
            game.setCurrentTurn(game.getCurrentTurn() + 1);
        }

        // Check for game end
        if (board.getPlayerPosition(0) >= 51 || board.getPlayerPosition(1) >= 51) {
            game.setIsNotDone(false);
        }
    }
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
