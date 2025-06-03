//
// Created by Johny on 05.12.2022.
//

#include "Item.h"

#include "Item.h"

Item::Item() {
    m_id++;

};

Item::~Item() {

}

int Item::getDamage() {
    return 0;
}

int Item::getBonus() {
    return 0;
}

std::string Item::getCureUnit() {
    return "";
}

int Item::getHowMuch() {
    return 0;
}
