//
// Created by cicva on 11/12/2022.
//

#include "HardEnemyFactory.h"

SmallEnemy* HardEnemyFactory::getSmallEnemy() {
    return new SmallEnemy(54,15,125);
}
AverageEnemy* HardEnemyFactory::getAverageEnemy() {
    return  new AverageEnemy(75,18,250);
}
HugeEnemy* HardEnemyFactory::getHugeEnemy() {
    return new HugeEnemy(150,15,500);
}