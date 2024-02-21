//
// Created by Workstation on 12.11.2022.
//

#ifndef DOKUMENTY_ARMOR_H
#define DOKUMENTY_ARMOR_H

#include "Item.h"

class Armor : public Item {
private:
    int m_bonus;
    int m_idCopy;
    std::string m_appereance;

public:
    Armor(std::string name, int bonus);

    Armor(Item* another);

    int getBonus() override;

    void printInfo() override;

    std::string getName() override;

    std::string getAppereance() override;

};

#endif //DOKUMENTY_ARMOR_H
