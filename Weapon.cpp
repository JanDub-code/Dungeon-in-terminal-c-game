//
// Created by Workstation on 12.11.2022.
//

#include "Weapon.h"

Weapon::Weapon(std::string name, int damage){
    m_damage = damage;
    m_idCopy = m_id;
    m_name = name;
    m_appereance = "Z";

}

Weapon::Weapon(Item* another){
    m_damage = another->getDamage();
    m_idCopy = m_id;
    m_name = another->getName();
    m_appereance = "Z";

};

void Weapon::printInfo() {

    std::cout<<"ID: "<<m_idCopy;
    std::cout<<" Nazev: "<<m_name<<std::endl;
    std::cout<<"Poskozeni: "<<m_damage<<std::endl;

    std::cout<<""<<std::endl;

};

int Weapon::getDamage() {
    return m_damage;

}

std::string Weapon::getName() {
    return m_name;

}

std::string Weapon::getAppereance() {
    return m_appereance;

}