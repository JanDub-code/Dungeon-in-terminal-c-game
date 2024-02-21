//
// Created by cicva on 11/12/2022.
//

#include "MediumEnemyFactory.h"

SmallEnemy* MediumEnemyFactory::getSmallEnemy() {
    return new SmallEnemy(40,15,125);
}
AverageEnemy* MediumEnemyFactory::getAverageEnemy() {
    return new AverageEnemy(70,15,250);
}
HugeEnemy* MediumEnemyFactory::getHugeEnemy() {
    return new HugeEnemy(110,15,500);
}