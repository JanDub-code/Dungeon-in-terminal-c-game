//
// Created by Johny on 05.12.2022.
//

#ifndef ZOO_PROJEKT_ITEM_H
#define ZOO_PROJEKT_ITEM_H

#include <iostream>

class Item {
protected:
    static int m_id;
    std::string m_name;

public:
    Item();

    ~Item();

    virtual void printInfo() = 0;

    virtual int getDamage();

    virtual int getBonus();

    virtual std::string getCureUnit();

    virtual int getHowMuch();

    virtual std::string getName() = 0;

    virtual std::string getAppereance() = 0;

};

#endif //ZOO_PROJEKT_ITEM_H
