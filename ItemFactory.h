//
// Created by Johny on 05.12.2022.
//

#ifndef ZOO_PROJEKT_ITEMFACTORY_H
#define ZOO_PROJEKT_ITEMFACTORY_H

#include <vector>
#include "Item.h"

class ItemFactory {
private:

public:

    Item *createWeapon(std::string name, int damage);

    Item *createPotion(std::string name, std::string cureUnit, int howMuch);

    Item *createArmor(std::string name, int bonus);

    Item *createItemCopy(Item *item);

};

#endif //ZOO_PROJEKT_ITEMFACTORY_H
