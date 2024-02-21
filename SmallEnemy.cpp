//
// Created by cicva on 11/12/2022.
//


#include "SmallEnemy.h"

SmallEnemy::SmallEnemy( int health,int strength,  int expToDrop) {
    m_strength = strength;
    m_health = health;
    m_expToDrop = expToDrop;
}

int SmallEnemy::getHealth() {
    return m_health;
}
int SmallEnemy::getStrength() {
    return m_strength;
}
int SmallEnemy::getDroppedExp() {
    return m_expToDrop;
}

void SmallEnemy::takeDamage(int damage) {
    m_health -= damage;
}
bool SmallEnemy::isDead() {
    if(m_health <=0){
        return true;
    }
    else{
        return false;
    }
}