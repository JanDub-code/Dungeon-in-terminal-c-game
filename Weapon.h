//
// Created by Workstation on 12.11.2022.
//

#ifndef DOKUMENTY_WEAPON_H
#define DOKUMENTY_WEAPON_H

#include "Item.h"

class Weapon : public Item {
private:
    int m_damage;
    int m_idCopy;
    std::string m_appereance;

public:
    Weapon(std::string name, int damage);

    Weapon(Item* another);

    int getDamage() override;

    void printInfo() override;

    std::string getName() override;

    std::string getAppereance() override;

};

#endif //DOKUMENTY_WEAPON_H
