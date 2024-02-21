//
// Created by cicva on 11/12/2022.
//

#ifndef ZOO_PROJEKT_ENEMYFACTORY_H
#define ZOO_PROJEKT_ENEMYFACTORY_H
#include <iostream>
#include "SmallEnemy.h"
#include "AverageEnemy.h"
#include "HugeEnemy.h"

class EnemyFactory {
    public:
        virtual SmallEnemy* getSmallEnemy() = 0;
        virtual AverageEnemy* getAverageEnemy() = 0;
        virtual HugeEnemy* getHugeEnemy() = 0;

};


#endif //ZOO_PROJEKT_ENEMYFACTORY_H
