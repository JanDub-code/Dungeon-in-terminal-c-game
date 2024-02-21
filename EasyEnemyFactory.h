//
// Created by cicva on 11/12/2022.
//

#ifndef ZOO_PROJEKT_EASYENEMYFACTORY_H
#define ZOO_PROJEKT_EASYENEMYFACTORY_H
#include "EnemyFactory.h"


class EasyEnemyFactory:public EnemyFactory {

public:
    SmallEnemy* getSmallEnemy();
    AverageEnemy* getAverageEnemy();
    HugeEnemy* getHugeEnemy();
};


#endif //ZOO_PROJEKT_EASYENEMYFACTORY_H
