#include "tile.h"

Tile::Tile(){
    color = ' ';
}
char Tile::getColor() const{
    return color;
}
void Tile::setColor(char c){
    color = c;
}
