//
// Created by cicva on 11/12/2022.
//
//Hlavickovy soubor ktery se spolecne s HugeEnemy.cpp stara o nastaveni nejsilnejsiho monstra jakekoliv obtiznosti
#ifndef ZOO_PROJEKT_HUGEENEMY_H
#define ZOO_PROJEKT_HUGEENEMY_H
#include <iostream>
#include "Enemy.h"

class HugeEnemy : public Enemy{
protected:
    int m_strength;
    int m_health;
    int m_expToDrop;
    bool m_isDead = false;
public:
   HugeEnemy(int health,int strength,int expToDrop);
    int getHealth();
    int getStrength();
    int getDroppedExp();
    bool isDead();
    void takeDamage(int damage);
};


#endif //ZOO_PROJEKT_HUGEENEMY_H
