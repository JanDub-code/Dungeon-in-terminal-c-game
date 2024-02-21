//
// Created by cicva on 11/12/2022.
//

#include "EasyEnemyFactory.h"

SmallEnemy* EasyEnemyFactory::getSmallEnemy() {
    return new SmallEnemy(30,10,125);
}
AverageEnemy* EasyEnemyFactory::getAverageEnemy() {
    return new AverageEnemy(50,15,250);
}
    HugeEnemy* EasyEnemyFactory::getHugeEnemy() {
    return new HugeEnemy(110,10,500);
}