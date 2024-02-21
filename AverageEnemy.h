//
// Created by cicva on 11/12/2022.
//
//Hlavickovy soubor ktery se spolecne s AverageEnemy.cpp stara o nastaveni stredniho monstra jakekoliv obtiznosti
#ifndef ZOO_PROJEKT_AVERAGEENEMY_H
#define ZOO_PROJEKT_AVERAGEENEMY_H
#include "Enemy.h"

class AverageEnemy : public Enemy{
protected:
    int m_strength;
    int m_health;
    int m_expToDrop;
    bool m_isDead = false;
public:
    AverageEnemy(int health,int strength,int expToDrop);
    int getHealth();
    int getStrength();
    int getDroppedExp();
    bool isDead();
    void takeDamage(int damage);

};


#endif //ZOO_PROJEKT_AVERAGEENEMY_H
