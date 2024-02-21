//
// Created by cicva on 12/3/2022.
//

#include "SaveAndLoad.h"

SaveAndLoad::SaveAndLoad(){};

//ukladani a vypisovani mapy
void SaveAndLoad::saveMapIntoMatrix(Map *map) {
    Map* savedMap = new Map(map->getWidth(), map->getHeight());
    for(int i= 0;i < map->getHeight();i++){
        for(int j = 0;j< map->getWidth();j++){
            savedMap->setNewAppearance(i,j,(map->getValue(i,j)->getAppearance()));
        }
    }
    m_savedMapMatrix->setValue(m_row,m_col,savedMap);
    m_col++;
    };

void SaveAndLoad::printSavedMap(unsigned int row, unsigned int col) {
    m_savedMapMatrix->printOutMap(row,col);
};
Map* SaveAndLoad::returnMap(unsigned int row, unsigned int col) {
    return m_savedMapMatrix->getValue(row,col);
}
//ukladani stavu hrace
void SaveAndLoad::savePlayerStatus(Player *player) {
    Player* temp = new Player(player->getHealth(),player->getStength(),player->getDexterity(),player->getLevel(),player->getName(),player->getClassName(),player->getXp(),
                             player->getNextLevelXp(),player->getAttack(),player->getDefence(),player->getEquippedArmor(),player->getEquippedWeapon(),player->returnX(),
                             player->returnY(),player->getPlayerSymbol());
    m_savedPlayerStatus = temp;
};
void SaveAndLoad::printSavedPlayerStatus() {
    m_savedPlayerStatus->viewStatistics('t');
};
