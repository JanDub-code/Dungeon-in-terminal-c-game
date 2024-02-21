//
// Created by cicva on 12/6/2022.
//

#ifndef ZOO_PROJEKT_ENEMY_H
#define ZOO_PROJEKT_ENEMY_H


class Enemy {
public:
    virtual int getHealth()=0;
    virtual int getStrength()=0;
    virtual int getDroppedExp()=0;
    virtual bool isDead()=0;
    virtual void takeDamage(int damage)=0;
    Enemy(){}
    virtual ~Enemy(){};
};


#endif //ZOO_PROJEKT_ENEMY_H
