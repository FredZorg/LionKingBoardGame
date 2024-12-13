//Abey Saleh and Fred Zordgrager Group Project
#include "board.h"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"
#define BLACK_BG "\033[48;2;0;0;0m"

using namespace std;

Player Board::isBlue(Player player){
    cout << "You’ve found a beautiful oasis! Enjoy!" << endl;
    cout << "+200 Wisdom" << endl << "+200 Strenght" << endl << "+200 Stamina" << endl;
    player.addWisdom(200);
    player.addStrength(200);
    player.addStamina(200);
    return player;
}

void Board::addPlayers(Player player1, Player player2){
    players[0] = player1;
    players[1] = player2;
}

//0 for cub path 1 for pride path
void Board::initializeBoard(int player1, int player2) {
    // Seed random number generator in your main function once
    if (player1 == 0){
        initializeCubPath(0);
    } else {
        initializePridePath(0);
    }
    if (player2 == 0){
        initializeCubPath(1);
    } else {
        initializePridePath(1);
    }


}

void Board::initializeCubPath(int player_index) {
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    const int OASIS_LIMIT = 39; //amount of tiles before you no longer can find an oasis
    const int GRAVEYARD_START = 13;

// Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++) {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } else if (i == 0) {
            // Set the starting tile Grey
            temp.color = 'Y';
        } else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count)) {
            temp.color = 'G';
            green_count++;
        } else {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            if (i <= GRAVEYARD_START){
                int color_choice = rand() % 4;
                switch (color_choice) {
                    case 0:
                        temp.color = 'B'; // Blue
                        break;
                    case 1:
                        temp.color = 'P'; // Pink
                        break;
                    case 2:
                        temp.color = 'N'; // Brown
                        break;
                    case 3:
                        temp.color = 'U'; // Purple
                        break;
                }
            } else if (i > GRAVEYARD_START && i <= OASIS_LIMIT) {
                int color_choice = rand() % 5;
                switch (color_choice) {
                    case 0:
                        temp.color = 'B'; // Blue
                        break;
                    case 1:
                        temp.color = 'P'; // Pink
                        break;
                    case 2:
                        temp.color = 'N'; // Brown
                        break;
                    case 3:
                        temp.color = 'R'; // Red
                        break;
                    case 4:
                        temp.color = 'U'; // Purple
                        break;
                }
            } else {
                int color_choice = rand() % 4;
                switch (color_choice) {
                    case 0:
                        temp.color = 'P'; // Pink
                        break;
                    case 1:
                        temp.color = 'N'; // Brown
                        break;
                    case 2:
                        temp.color = 'R'; // Red
                        break;
                    case 3:
                        temp.color = 'U'; // Purple
                        break;
                    }
                }
            }
    // Assign the tile to the board for the specified lane
    _tiles[player_index][i] = temp;
    }
}

void Board::initializePridePath(int player_index) {
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    const int OASIS_LIMIT = 39; //amount of tiles before you no longer can find an oasis
    const int GRAVEYARD_START = 26; //amount of tiles before you see any graveyards

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++) {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } else if (i == 0) {
             // Set the starting tile Grey
            temp.color = 'Y';
        } else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count)) {
            temp.color = 'G';
            green_count++;
        } else {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            if (i < GRAVEYARD_START){
                int color_choice = rand() % 5;
                switch (color_choice) {
                    case 0:
                        temp.color = 'B'; // Blue
                        break;
                    case 1:
                        temp.color = 'P'; // Pink
                        break;
                    case 2:
                        temp.color = 'N'; // Brown
                        break;
                    case 3:
                        temp.color = 'U'; // Purple
                        break;
                    case 4:
                        temp.color = 'P'; // Pink
                        break;
                }
            } else if (i >= GRAVEYARD_START && i <= OASIS_LIMIT) {
                int color_choice = rand() % 5;
                switch (color_choice) {
                    case 0:
                        temp.color = 'B'; // Blue
                        break;
                    case 1:
                        temp.color = 'P'; // Pink
                        break;
                    case 2:
                        temp.color = 'N'; // Brown
                        break;
                    case 3:
                        temp.color = 'R'; // Red
                        break;
                    case 4:
                        temp.color = 'U'; // Purple
                        break;
                }
            } else {
                int color_choice = rand() % 4;
                switch (color_choice) {
                    case 0:
                        temp.color = 'P'; // Pink
                        break;
                    case 1:
                        temp.color = 'N'; // Brown
                        break;
                    case 2:
                        temp.color = 'R'; // Red
                        break;
                    case 3:
                        temp.color = 'U'; // Purple
                        break;
                    }
                }
            }
        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}

Board::Board() {
    // Initialize player position
    for (int i = 0; i < _MAX_PLAYERS; i++) {
        _player_position[i] = 0;
    }

}

Board::Board(int player1, int player2) {
    // Initialize player position
    for (int i = 0; i < _MAX_PLAYERS; i++) {
        _player_position[i] = 0;
    }

    // Initialize tiles
    initializeBoard(player1, player2);
}

bool Board::isPlayerOnTile(int player_index, int pos) {
    if (_player_position[player_index] == pos) {
        return true;
    }
        return false;
}

void Board::displayTile(int player_index, int pos) {
    // string space = " ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>
    // Determine color to display
    if (_tiles[player_index][pos].color == 'R') {
        color = RED;
    } else if (_tiles[player_index][pos].color == 'G') {
        color = GREEN;
    } else if (_tiles[player_index][pos].color == 'B') {
        color = BLUE;
    } else if (_tiles[player_index][pos].color == 'U') {
        color = PURPLE;
    } else if (_tiles[player_index][pos].color == 'N') {
        color = BROWN;
    } else if (_tiles[player_index][pos].color == 'P') {
        color = PINK;
    } else if (_tiles[player_index][pos].color == 'O') {
        color = ORANGE;
    } else if (_tiles[player_index][pos].color == 'Y') {
        color = GREY;
    } if (player == true) {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
    } else {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int player_index) {
    for (int i = 0; i < _BOARD_SIZE; i++) {
        displayTile(player_index, i);
    }
    cout << "\033[49m\033[K" << RESET << endl;
}

void Board::displayBoard() {
    for (int i = 0; i < 2; i++) {
        displayTrack(i);
        if (i == 0) {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}

char Board::getTileColor(int player_index, int position) const {
    return _tiles[player_index][position].color;
}

// board.cpp
void Board::setPlayer(int index, Player player) {
    if (index >= 0 && index < 2) {
        players[index] = player;
    }
}

Player Board::movePlayer(int player_index, int dist) {
    // Store original position for brown tile
    int originalPosition = _player_position[player_index];

    // Increment player position
    if (dist + _player_position[player_index] >= 52){
        _player_position[player_index] = 52;
        players[player_index].setGameIsDone(true);
        return players[player_index];
    } else if (dist + _player_position[player_index] <= 1){
        _player_position[player_index] = 1;
    } else {
        _player_position[player_index] += dist;
    }

    if (dist == -10){
        return players[player_index];
    }

    char currentColor = _tiles[player_index][_player_position[player_index]].color;
    bool entryValid = false;
    int entry;

    switch(currentColor) {
        case 'B': // Blue - Oasis
            cout << "You landed on a blue tile! You get another turn!" << endl;
            players[player_index].addBlueCounter(players[player_index]);
            return isBlue(players[player_index]);

        case 'R': // Red - Graveyard
            cout << "Uh-oh, you've stumbled into the Graveyard!" << endl;
            cout << "-100 to all stats and moving back 10 tiles!" << endl;
            players[player_index].addWisdom(-100);
            players[player_index].addStrength(-100);
            players[player_index].addStamina(-100);
            _player_position[player_index] = max(1, _player_position[player_index] - 10);
            
            players[player_index].addRedCounter(players[player_index]);
            
            return players[player_index];

        case 'P': // Pink - Enrichment
            cout << "Welcome to the land of enrichment!" << endl;
            cout << "+300 to all stats!" << endl;
            cout << "You also get to pick an advisor!!!" << endl;
            
            while (!entryValid) {
                cout << players[player_index].getPlayerName() << " type 1 if you are ready to pick an advisor." << endl;
                cin >> entry;
                if (entry == 1){
                    entryValid = true;
                } else {
                    cout << "That is an invalid input please input 1." << endl;
                }
            }
            
            players[player_index].addWisdom(300);
            players[player_index].addStrength(300);
            players[player_index].addStamina(300);
            return players[player_index];

        case 'N': // Brown - Hyenas
            cout << "You got caught by Hyenas!" << endl;
            cout << "-300 to all stats and you don't move forward!" << endl;
            players[player_index].addWisdom(-300);
            players[player_index].addStrength(-300);
            players[player_index].addStamina(-300);
            _player_position[player_index] = originalPosition;
            return players[player_index];

        case 'U': // Purple - Riddle
        case 'G': // Green - Random Event
            return _tiles[player_index][_player_position[player_index]].getMessage(players[player_index], player_index);

        default: // Grey, Orange, or other
            return players[player_index];
    }
}

int Board::getPlayerPosition(int player_index) const {
    if (player_index >= 0 && player_index <= _player_count) {
        return _player_position[player_index];
    }
    return -1;
}
