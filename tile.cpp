#include "tile.h"

//takes in the player and the tile color, based of the tile color it does different things
Player Tile::getMessage(Player player, int player_input){


    return player;
}

Player Tile::isBlue(Player player){
    cout << "You’ve found a beautiful oasis! Enjoy!" << endl;
    cout << "+200 Wisdom" << endl << "+200 Strenght" << endl << "+200 Stamina" << endl;
    player.addWisdom(200);
    player.addStrength(200);
    player.addStamina(200);
    return player;
}

Player Tile::isRed(Player player, int player_input){
    cout << "Uh-oh, you’ve stumbled into the Graveyard! You take a hit to your stats." << endl;
    cout << "-100 Wisdom" << endl << "-100 Strenght" << endl << "-100 Stamina" << endl << "-10 tiles" << endl;
    player.addWisdom(-100);
    player.addStrength(-100);
    player.addStamina(-100);

    return player;

}

Player Tile::isPink(Player player){
    cout << "Welcome to the land of enrichment! Enjoy this boost to your stats!" << endl;
    cout << "+300 Wisdom" << endl << "+300 Strenght" << endl << "+300 Stamina" << endl;
    cout << "You also get to swap/pick an advisor" << endl;
    player.addWisdom(300);
    player.addStrength(300);
    player.addStamina(300);

    return player;
}

Player Tile::isBrown(Player player){

    return player;
}

Player Tile::isPurple(Player player){

    return player;
}

Player Tile::isGreen(Player player){

    return player;
}
