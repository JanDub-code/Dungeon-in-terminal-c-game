//
// Created by cicva on 11/12/2022.
//

#include "HugeEnemy.h"

HugeEnemy::HugeEnemy(int health, int strength, int expToDrop) {

    m_strength = strength;
    m_health = health;
    m_expToDrop = expToDrop;
}
int HugeEnemy::getHealth() {
    return m_health;
};
int HugeEnemy::getStrength() {
    return m_strength;
}
int HugeEnemy::getDroppedExp() {
    return m_expToDrop;
}
void HugeEnemy::takeDamage(int damage) {
    m_health -= damage;
}
bool HugeEnemy::isDead() {
    if(m_health <=0){
        return true;
    }
    else{
        return false;
    }
}