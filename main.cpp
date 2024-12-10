#include <iostream>
#include <vector>
#include <string>
#include "game.h"
#include "board.h"


using namespace std;

void startGame();

int main(){
    srand(time(0));
    cout << "Testing Cub Path vs Pride Path:\n";
        Board board(0, 1);  // Player 1 on Cub Path, Player 2 on Pride Path

        // Display initial board
        cout << "\nInitial board state:\n";
        board.displayBoard();

        // Test some movements
        cout << "\nMoving Player 1 forward 3 spaces:\n";
        board.movePlayer(0, 3);
        board.displayBoard();

        cout << "\nMoving Player 2 forward 5 spaces:\n";
        board.movePlayer(1, 5);
        board.displayBoard();

        // Test boundary movement
        cout << "\nTesting boundary movement (moving Player 1 back 2 spaces):\n";
        board.movePlayer(0, -2);
        board.displayBoard();
}

void startGame() {

}
