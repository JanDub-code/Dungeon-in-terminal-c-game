//
// Created by Johny on 05.12.2022.
//

#include "ItemFactory.h"
#include "Weapon.h"
#include "Potion.h"
#include "Armor.h"


Item *ItemFactory::createWeapon(std::string name, int damage) {
    return new Weapon(name, damage);

};

Item *ItemFactory::createPotion(std::string name, std::string cureUnit, int howMuch) {
    return new Potion(name, cureUnit, howMuch);

};

Item *ItemFactory::createArmor(std::string name, int bonus) {
    return new Armor(name, bonus);

};

Item *ItemFactory::createItemCopy(Item *item) {
    std::string test = typeid(*item).name(); // zjištění, o jaký typ potomka se jedná

    if(test == "6Weapon") {
        return new Weapon(item);
    }

    else if(test == "6Potion") {
        return new Potion(item);
    }

    else if(test == "5Armor") {
        return new Armor(item);
    }

};