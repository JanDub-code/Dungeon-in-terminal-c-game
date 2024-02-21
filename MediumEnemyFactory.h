//
// Created by cicva on 11/12/2022.
//
#ifndef ZOO_PROJEKT_MEDIUMENEMYFACTORY_H
#define ZOO_PROJEKT_MEDIUMENEMYFACTORY_H
#include "EnemyFactory.h"


class MediumEnemyFactory:public EnemyFactory {
public:
    SmallEnemy* getSmallEnemy();
    AverageEnemy* getAverageEnemy();
    HugeEnemy* getHugeEnemy();
};


#endif //ZOO_PROJEKT_MEDIUMENEMYFACTORY_H
