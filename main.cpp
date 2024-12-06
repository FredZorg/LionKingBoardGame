#include <iostream>
#include <vector>
#include <string>
#include "game.cpp"


using namespace std;

void startGame();

int main(){
    Game game;

    // Create player object
    Player testPlayer;

    // Initialize the lions vector
    game.createLionsVector();

    // Test the lion selection menu
    cout << "Testing Lion Selection Menu:" << endl;
    game.lionSelectionMenu(testPlayer);

    // Optionally print the selected lion's stats to verify
    cout << "\nSelected Lion Stats:" << endl;
    cout << "Name: " << testPlayer.getLionName() << endl;
    cout << "Age: " << testPlayer.getAge() << endl;
    cout << "Strength: " << testPlayer.getStrength() << endl;
    cout << "Stamina: " << testPlayer.getStamina() << endl;
    cout << "Wisdom: " << testPlayer.getWisdom() << endl;
}

void startGame() {

}
