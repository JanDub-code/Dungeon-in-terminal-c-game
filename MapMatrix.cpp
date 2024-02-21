//
// Created by Workstation on 29.11.2022.
//

#include "MapMatrix.h"

MapMatrix::MapMatrix(unsigned int width, unsigned int height) {
    if (width > 0 && height > 0) {

        for (int x = 0; x < height; x++) {
            std::vector<Map *> row;

            for (int y = 0; y < width; y++) {
                row.push_back(new Map() );
            }

            m_map.push_back(row);
        }

    } else {
        std::cerr << "Cannot initialize the map!" << std::endl;
    }
}



Map *MapMatrix::getValue(unsigned int row, unsigned int col) {
    if (row, col) {
        return m_map.at(row).at(col);
    } else {
        return nullptr;
    }
}

void MapMatrix::setValue(unsigned int row, unsigned int col, Map *value){
    delete m_map.at(row).at(col); // delete the old tile to prevent memory leak
    m_map.at(row).at(col) = value;

}

void MapMatrix::printOutMap(unsigned int row, unsigned int col) {
    if (row, col) {
        m_map.at(row).at(col)->print();
    }
}

void MapMatrix::printAllValuesInMatrix() {
    for (std::vector<Map *> row: m_map) {
        for (Map *cell: row) {
            cell->print();
        }
        std::cout << std::endl;
    }
}

MapMatrix::~MapMatrix() {
    for (auto row: m_map) {
        for (auto cell: row) {
            delete cell;
        }
    }
}
