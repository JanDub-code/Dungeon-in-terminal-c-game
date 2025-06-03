//
// Created by Workstation on 29.11.2022.
//

#ifndef ZOO_PROJEKT_MAPMATRIX_H
#define ZOO_PROJEKT_MAPMATRIX_H

#include <vector>
#include "Map.h"

class MapMatrix {
    std::vector<std::vector<Map *> > m_map;
    bool isInMatrix(unsigned int row, unsigned int col);
public:
    MapMatrix(unsigned int width, unsigned int height);

    Map *getValue(unsigned int row, unsigned int col);

    void setValue(unsigned int row, unsigned int col, Map *value);

    void printOutMap(unsigned int row, unsigned int col);

    void printAllValuesInMatrix();

    ~MapMatrix();
};
#endif //ZOO_PROJEKT_MAPMATRIX_H
