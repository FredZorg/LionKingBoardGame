#include <iostream>
#include <vector>
#include <string>
#include "game.h"
//#include "board.h"



using namespace std;

void startGame();

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

void startGame() {

}
