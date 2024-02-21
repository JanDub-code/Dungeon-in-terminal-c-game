//
// Created by Johny on 27.11.2022.
//

#ifndef CV09_GRID_MAP_H
#define CV09_GRID_MAP_H

#include <vector>
#include <iostream>
#include "Tile.h"

class Map {
    std::vector<std::vector<Tile *> > m_map;
    int m_width;
    int m_height;
public:
    Map(unsigned int width, unsigned int height);

    Map();

    int getWidth();

    int getHeight();

    void findDoor(Map*map);

    Tile *getValue(unsigned int row, unsigned int col);

    void setValue(unsigned int row, unsigned int col, Tile *value);

    void setNewAppearance(unsigned int row, unsigned int col, std::string appearance);

    void print();

    ~Map();

private:

    bool isInMap(unsigned int row, unsigned int col);
};


#endif //CV09_GRID_MAP_H
