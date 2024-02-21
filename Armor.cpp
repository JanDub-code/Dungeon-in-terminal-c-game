//
// Created by Workstation on 12.11.2022.
//

#include "Armor.h"

Armor::Armor(std::string name, int bonus){
    m_bonus = bonus;
    m_idCopy = m_id;
    m_name = name;
    m_appereance = "B";

}

Armor::Armor(Item* another){
    m_bonus = another->getBonus();
    m_idCopy = m_id;
    m_name = another->getName();
    m_appereance = "B";

};

void Armor::printInfo() {

    std::cout<<"ID: "<<m_idCopy;
    std::cout<<" Nazev: "<<m_name<<std::endl;
    std::cout<<"Bonus: "<<m_bonus<<std::endl;

    std::cout<<""<<std::endl;

};

int Armor::getBonus() {
    return m_bonus;

}

std::string Armor::getName() {
    return m_name;

}

std::string Armor::getAppereance() {
    return m_appereance;

}