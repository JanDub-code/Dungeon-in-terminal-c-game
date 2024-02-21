//
// Created by cicva on 12/6/2022.
//

#ifndef ZOO_PROJEKT_COMBAT_H
#define ZOO_PROJEKT_COMBAT_H
#include "Player.h"
#include "Enemy.h"

class Combat {
public:
    Combat();
    bool engage(Player* player,Enemy* monster);
    void fullHit(Player* player,Enemy* monster);
    void halfHit(Player* player,Enemy* monster);
    void displayCombatText(Player* player,Enemy* monster);
    void displayCombatResult(Player* player,Enemy* monster);
};


#endif //ZOO_PROJEKT_COMBAT_H
