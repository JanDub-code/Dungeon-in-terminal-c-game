//
// Created by Johny on 05.12.2022.
//

#include "Potion.h"

#include "Potion.h"

Potion::Potion(std::string name, std::string cureUnit, int howMuch){
    m_cureUnit = cureUnit;
    m_howMuch = howMuch;
    m_idCopy = m_id;
    m_name = name;
    m_appereance = "L";

}

Potion::Potion(Item* another){
    m_cureUnit = another->getCureUnit();
    m_howMuch = another->getHowMuch();
    m_idCopy = m_id;
    m_name = another->getName();
    m_appereance = "L";

};

void Potion::printInfo() {
    std::cout<<"ID: "<<m_idCopy;
    std::cout<<" Jmeno: "<<m_name<<std::endl;
    std::cout<<"Co lektvar leci: "<<m_cureUnit<<std::endl;
    std::cout<<"Jak moc leci: "<<m_howMuch<<std::endl;

    std::cout<<""<<std::endl;

};

std::string Potion::getName() {
    return m_name;

}

std::string Potion::getCureUnit() {
    return m_cureUnit;
};

int Potion::getHowMuch() {
    return m_howMuch;

}

std::string Potion::getAppereance() {
    return m_appereance;

}