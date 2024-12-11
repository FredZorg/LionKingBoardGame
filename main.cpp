#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cctype>
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
    int random;
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
    cout << "Great! Player two please enter your name." << endl;
    cin >> inputS;
    player2.setPlayerName(inputS);

    cout << "To pick the starting order "<< player1.getPlayerName() << " must pick either 1 or 2." << endl;
    if (playerOneStarts(player1,player2)){
        game.setCurrentTurn(0);
    } else {
        game.setCurrentTurn(1);
    }

    //select lions
    player1 = game.lionSelectionMenu(player1);
    player2 = game.lionSelectionMenu(player2);

    trainOrCub1 = game.prideOrTrain(player1);
    trainOrCub2 = game.prideOrTrain(player2);

    board.initializeBoard(trainOrCub1, trainOrCub2);

    while (game.getIsNotDone()) {
        Game::GameState state;
        if(game.getCurrentTurn() % 2 == 0){
            state = game.rollOrMenuInput(player1, board);
            player1 = state.player;
            board = state.board;
        } else {
            state = game.rollOrMenuInput(player2, board);
            player2 = state.player;
            board = state.board;
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
        return true;
    }

    return false;
}
