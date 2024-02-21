//
// Created by Johny on 27.11.2022.
//

#ifndef CV09_GRID_TILE_H
#define CV09_GRID_TILE_H

#include <iostream>
#include <vector>
#include "Item.h"
#include "Enemy.h"

class Tile {
    std::string m_appearance;
    std::vector<Item*>m_items;
    std::vector<Enemy*>m_enemies;
public:
    Tile(std::string appearance);

    void setAppearance(std::string appearance);

    std::string getAppearance();

    void setEnemies(Enemy* enemies);

    void setItems(Item* items);

    std::vector<Enemy *> getEnemies();

    std::vector<Item *> getItems();
};


#endif //CV09_GRID_TILE_H
