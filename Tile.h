#ifndef TILE_H
#define TILE_H

class Tile {
    private:
        char color;

    public:
        Tile();
        char getColor() const;
        void setColor(char c);

        friend class Board;

};

#endif
