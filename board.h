#ifndef BOARD_H
#define BOARD_H
#include "tile.h"

class Board
{
private:
    static const int MAX_PLAYERS = 2;
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    int _player_position[_MAX_PLAYERS];
    Player players[MAX_PLAYERS];
    void displayTile(int player_index, int pos);
    void initializePridePath(int player_index);
    void initializeCubPath(int player_index);
    bool isPlayerOnTile(int player_index, int pos);
public:
    Board();
    Board(int player1, int player2);
    Board(int player_count);
    void displayTrack(int player_index);
    void initializeBoard(int player1, int player2);
    void displayBoard();
    Player movePlayer(int player_index, int dist);
    int getPlayerPosition(int player_index) const;
    void addPlayers(Player player1, Player player2);
};

#endif
