//
// Created by cicva on 12/3/2022.
//

#ifndef ZOO_PROJEKT_SAVEANDLOAD_H
#define ZOO_PROJEKT_SAVEANDLOAD_H
#include <vector>
#include "Map.h"
#include "Tile.h"
#include "Player.h"
#include "MapMatrix.h"


class SaveAndLoad {
    unsigned int m_height = 5;
    unsigned int m_width = 5;
    unsigned int m_row = 1;
    unsigned int m_col = 1;
    MapMatrix* m_savedMapMatrix = new MapMatrix(m_width,m_height);
    Player* m_savedPlayerStatus;

public:
    SaveAndLoad();
    void saveMapIntoMatrix (Map *map);
    void printSavedMap(unsigned int row,unsigned int col);
    Map *returnMap(unsigned int row,unsigned int col);
    void savePlayerStatus(Player *player);
    void printSavedPlayerStatus();
};


#endif //ZOO_PROJEKT_SAVEANDLOAD_H
