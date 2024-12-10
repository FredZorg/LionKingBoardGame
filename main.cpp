#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cctype>
#include "game.h"
//#include "board.h"

using namespace std;

void startGame();
bool playerOneStarts(Player playerOne, Player playerTwo);

int main(){
    srand(time(0));
    Player player;
    Player player2;
    Game game(1);
    // First populate the lions vector
    game.createLionsVector();
    game.createAdvisorVector();

    // Test lion selection menu
    cout << "\nTesting Advisor Selection Menu:\n" << endl;

    player = game.advisorSelectionMenu(player);
    cout << "\nVerifying selected lion's attributes:\n" << endl;
    cout << "Selected Advisors Name: " << player.getAdvisorName() << endl;
    cout << "Ability: " << player.getAdvisorAbility() << endl;

    player = game.advisorSelectionMenu(player2);
    cout << "\nVerifying selected lion's attributes:\n" << endl;
    cout << "Selected Advisors Name: " << player.getAdvisorName() << endl;
    cout << "Ability: " << player.getAdvisorAbility() << endl;

    player = game.advisorSelectionMenu(player);
    cout << "\nVerifying selected lion's attributes:\n" << endl;
    cout << "Selected Advisors Name: " << player.getAdvisorName() << endl;
    cout << "Ability: " << player.getAdvisorAbility() << endl;

}

void startGame(){
    Player player1;
    Player player2;
    string inputS;
    int random;

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

    } else {
        
    }

}

bool playerOneStarts(Player playerOne, Player playerTwo){
    int random = rand() % 2 + 1;
    int choice = 0;

    cout << "What is your choice?" << endl;
    cin >> choice;

    if ((choice != 1) && (choice != 2)){
        cout << "That is an invalid entry, please enter either 1 or 2." << endl;
    } else if (choice == random) {
        return true;
    }

    return false;
}
