//
// Created by Johny on 05.12.2022.
//

#ifndef ZOO_PROJEKT_POTION_H
#define ZOO_PROJEKT_POTION_H

#include "Item.h"

class Potion : public Item {
private:
    std::string m_cureUnit;
    int m_howMuch;
    int m_idCopy;
    std::string m_appereance = "L";

public:
    Potion(std::string name, std::string cureUnit, int howMuch);

    Potion(Item* another);

    std::string getCureUnit() override;

    int getHowMuch() override;

    void printInfo() override;

    std::string getName() override;

    std::string getAppereance() override;

};

#endif //ZOO_PROJEKT_POTION_H
