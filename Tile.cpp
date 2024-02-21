//
// Created by Johny on 27.11.2022.
//

#include "Tile.h"

Tile::Tile(std::string appearance) {
    m_appearance = appearance;
    m_enemies={};
    m_items={};
}

void Tile::setAppearance(std::string appearance) {
    m_appearance = appearance;
}

std::string Tile::getAppearance() {
    return m_appearance;
}

void Tile::setEnemies(Enemy* enemies) {
    m_enemies.push_back(enemies);
}

void Tile::setItems(Item* items) {
    m_items.push_back(items);
}

std::vector<Enemy *> Tile::getEnemies() {
    return m_enemies;
}

std::vector<Item *> Tile::getItems() {
    return m_items;
}