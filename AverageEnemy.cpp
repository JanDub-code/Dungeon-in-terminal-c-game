//
// Created by cicva on 11/12/2022.
//

#include "AverageEnemy.h"

AverageEnemy::AverageEnemy(int health, int strength, int expToDrop) {

    m_strength = strength;
    m_health = health;
    m_expToDrop = expToDrop;
}
int AverageEnemy::getHealth(){
    return m_health;
}
int AverageEnemy::getStrength() {
    return m_strength;
}
int AverageEnemy::getDroppedExp() {
    return m_expToDrop;
}
void AverageEnemy::takeDamage(int damage) {
    m_health -= damage;
}
bool AverageEnemy::isDead() {
    if(m_health <=0){
        return true;
    }
    else{
        return false;
    }
}
