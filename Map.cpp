 //
// Created by Johny on 27.11.2022.
//

#include "Map.h"

Map::Map(unsigned int width, unsigned int height) {
    m_width =width;
    m_height=height;
    if (width > 0 && height > 0) {

        for (int x = 0; x < height; x++) {
            std::vector<Tile *> row;

            for (int y = 0; y < width; y++) {
                row.push_back(new Tile(y == 0  || y == width-1 || x == 0 || x == height-1 ? "#" : " "));
            }

            m_map.push_back(row);
        }

    } else {
        std::cerr << "Cannot initialize the map!" << std::endl;
    }
}

Map::Map(){}

int Map::getHeight() {
     return m_height;
}

int Map::getWidth() {
     return m_width;
}

 void Map::findDoor(Map *map) {
     for (int i = 0; i < map->getWidth() - 1; i++) {
         for (int j = 0; j < map->getHeight() - 1; j++) {
             if (map->getValue(i, j)->getAppearance() == "D") {
                 int positionX = i;
                 int positionY = j;
                 std::cout << "Door is at: " << positionX << ", " << positionY << std::endl;
             }
         }
     }
}

bool Map::isInMap(unsigned int row, unsigned int col) {
    if (row >= m_map.size()) { // m_map.size() == height
        //std::cerr << "Map::isInMap: row is " << row
                  //<< ", max. is  " << m_map.size() - 1 << std::endl;
        return false;
    }

    if (col >= m_map.at(0).size()) { // m_map.at(0).size() == width
        //std::cerr << "Map::isInMap: column is " << col
                  //<< ", max. is  " << m_map.at(0).size() - 1 << std::endl;
        return false;
    }

    return true;
}

Tile *Map::getValue(unsigned int row, unsigned int col) {
    if (isInMap(row, col)) {
        return m_map.at(row).at(col);
    } else {
        return nullptr;
    }
}

void Map::setValue(unsigned int row, unsigned int col, Tile *value) {
    if (isInMap(row, col)) {
        delete m_map.at(row).at(col); // delete the old tile to prevent memory leak
        m_map.at(row).at(col) = value;
    }
}

void Map::setNewAppearance(unsigned int row, unsigned int col, std::string appearance) {
    if (isInMap(row, col)) {
        m_map.at(row).at(col)->setAppearance(appearance);
    }
}


void Map::print() {
    for (std::vector<Tile *> row: m_map) {
        for (Tile *cell: row) {
            std::cout << cell->getAppearance() << " ";
        }
        std::cout << std::endl;
    }
}

Map::~Map() {
    for (auto row: m_map) {
        for (auto cell: row) {
            delete cell;
        }
    }
}
