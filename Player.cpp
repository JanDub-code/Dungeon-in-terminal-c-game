//
// Created by Workstation on 11.11.2022.
//

#include <iostream>
#include "Player.h"

Player::Player(){
    m_name = "Default";
    m_className = "Default";
    m_dexterity = 0;
    m_health = 0;
    m_healthCopy = 0;
    m_strength = 0;
    m_attack = 0;
    m_defence = 0;
    m_attackCopy = 0;
    m_defenceCopy = 0;
    m_level = 0;
    m_xp = 0;
    m_nextLevelXp = 0;
    m_equippedArmor = nullptr;
    m_equippedWeapon = nullptr;
    int m_x;
    int m_y;
    std::string symbol;
    m_inventory;


}

bool Player::isDead() {
    if(m_health<=0){
        return true;
    }
    else{
        return false;
    }
}

void Player::equippArmor(int armorNum) {
    int i = 0;
    int num = 0;
    for(auto armor:m_inventory) {
        std::string test = typeid(*armor).name(); // zjištění, o jaký typ potomka se jedná

        if(test == "5Armor") {
            i++;
        }

        if(i == armorNum) {
            if(m_equippedArmor == nullptr) {
                m_equippedArmor = armor;
                m_defence = armor->getBonus() + m_defenceCopy;

                m_inventory.erase(m_inventory.begin() + num);

            } else {
                m_inventory.push_back(m_equippedArmor);
                m_equippedArmor = armor;
                m_defence = armor->getBonus() + m_defenceCopy;

                m_inventory.erase(m_inventory.begin() + num);

            }
            break;
        }
        num++;
    }
}

void Player::equippWeapon(int weaponNum) {
    int i = 0;
    int num = 0;
    for(auto weapon:m_inventory) {
        std::string test = typeid(*weapon).name(); // zjištění, o jaký typ potomka se jedná

        if(test == "6Weapon") {
            i++;
        }

        if(i == weaponNum) {
            if(m_equippedWeapon == nullptr) {
                m_equippedWeapon = weapon;
                m_attack = weapon->getDamage() + m_attackCopy;

                m_inventory.erase(m_inventory.begin() + num);

            } else {
                m_inventory.push_back(m_equippedWeapon);
                m_equippedWeapon = weapon;
                m_attack = weapon->getDamage() + m_attackCopy;

                m_inventory.erase(m_inventory.begin() + num);

            }
            break;
        }
        num++;
    }
}

void Player::createClass() {
    std::cout << "Vytvareni postavy" << std::endl;
    std::cout << "==========================" << std::endl;

    std::cout << "Zadejte jmeno postavy: ";
    std::cin >> m_name;

    std::cout << "Vyberte tridu postavy..." << std::endl;
    std::cout << "1: Rytir 2: Assasin 3: Lucisnik: ";
    char characterNum = '1';
    std::cin >> characterNum;

    while ((characterNum != '1' and characterNum != '2' and characterNum != '3')) {
        std::cout << "Spatna volba. Zkuste to prosim znova"<<std::endl;
        std::cin >> characterNum;
    }

    switch (characterNum) {
        case '1':
            m_className = "Rytir";
            m_strength = 20;
            m_dexterity = 10;
            m_defence += m_dexterity / 2;
            m_attack += m_strength;
            m_attackCopy = m_attack;
            m_defenceCopy = m_defence;
            m_health = 50;
            m_healthCopy = m_health;
            m_nextLevelXp = 500;
            m_level = 1;
            m_xp = 0;
            m_equippedWeapon = nullptr;
            m_equippedArmor = nullptr;


            break;

        case '2':
            m_className = "Assasin";
            m_strength = 14;
            m_dexterity = 24;
            m_defence += m_dexterity / 2;
            m_attack += m_strength;
            m_attackCopy = m_attack;
            m_defenceCopy = m_defence;
            m_health = 42;
            m_healthCopy = m_health;
            m_nextLevelXp = 500;
            m_level = 1;
            m_xp = 0;
            m_equippedWeapon = nullptr;
            m_equippedArmor = nullptr;

            break;

        case '3':
            m_className = "Lucisnik";
            m_strength = 10;
            m_dexterity = 30;
            m_defence += m_dexterity / 2;
            m_attack += m_dexterity-10;
            m_attackCopy = m_attack;
            m_defenceCopy = m_defence;
            m_health = 36;
            m_healthCopy = m_health;
            m_nextLevelXp = 500;
            m_level = 1;
            m_xp = 0;
            m_equippedWeapon = nullptr;
            m_equippedArmor = nullptr;

            break;
    }
}

void Player::viewStatistics(char input) {
    if(input == 't') {
        std::cout << "STATISTIKY HRACE" << std::endl;
        std::cout << "============" << std::endl;
        std::cout << std::endl;

        std::cout << "Jmeno  = " << m_name << std::endl;
        std::cout << "Trida = " << m_className << std::endl;
        std::cout << "Zivot= " <<m_health  << std::endl;
        std::cout << "Sila  = " <<m_strength  << std::endl;
        std::cout << "Obratnost = " << m_dexterity << std::endl;
        std::cout << "Utok = " << m_attack << std::endl;
        std::cout << "Obrana = " << m_defence << std::endl;
        std::cout << "Xp    = " << m_xp << std::endl;
        std::cout << "Xp potrebne k dalsi urovni = " <<m_nextLevelXp  << std::endl;
        std::cout << "Uroven = " << m_level << std::endl;

        std::cout << "Brneni = "; if(m_equippedArmor != nullptr) {m_equippedArmor->printInfo();} std::cout<< std::endl;
        std::cout <<"Zbran = "; if(m_equippedWeapon != nullptr) {m_equippedWeapon->printInfo();} std::cout<<std::endl;

        std::cout << std::endl;
        std::cout << "KONEC STATISTIKY HRACE" << std::endl;
        std::cout << "================" << std::endl;
        std::cout << std::endl;

    }
}

void Player::viewInventory(char input) {
    if(input == 'i') {
        if(m_inventory.size() == 0) {
            std::cout<<std::endl;
            std::cout<<"Nemate zadne polozky v inventari"<<std::endl;
            std::cout<<std::endl;

            } else {
            std::cout<<std::endl;
            for(auto itm: m_inventory) {
                itm->printInfo();

            }

        }
    }
}

void Player::viewSeparateInventory(char input) {
        if(m_inventory.size() == 0) {
            std::cout<<std::endl;
            std::cout<<"Nemate zadne polozky v inventari"<<std::endl;
            std::cout<<std::endl;
        } else {
            std::cout<<std::endl;
            if(input == 'z') {
                for(auto weapon: m_inventory) {
                    std::string test = typeid(*weapon).name(); // zjištění, o jaký typ potomka se jedná

                    if(test == "6Weapon") {
                        weapon->printInfo();

                    }

                }
            }
            else if(input == 'b') {
                for(auto armor: m_inventory) {
                    std::string test = typeid(*armor).name(); // zjištění, o jaký typ potomka se jedná

                    if(test == "5Armor") {
                        armor->printInfo();

                    }

                }

        }

    }
}

Player::Player(int x, int y, std::string symbol) {
    m_name = "Default";
    m_className = "Default";
    m_dexterity = 0;
    m_health = 0;
    m_strength = 0;
    m_attack = 0;
    m_defence = 0;
    m_level = 0;
    m_xp = 0;
    m_nextLevelXp = 0;
    m_equippedArmor = nullptr;
    m_equippedWeapon = nullptr;
    this->m_x = y;
    this->m_y = x;
    this->symbol = symbol;
}
Player::Player(int health, int strength, int dexterity, int level, std::string name, std::string classname, int xp,
               int nextlevelxp, int attack, int defence, Item* equippedarmor, Item* equippedweapon, int x, int y,
               std::string symbol) {
    m_name = name;
    m_className = classname;
    m_dexterity = dexterity;
    m_health = health;
    m_strength = strength;
    m_attack = attack;
    m_defence = defence;
    m_level = level;
    m_xp = xp;
    m_nextLevelXp = nextlevelxp;
    m_equippedArmor = equippedarmor;
    m_equippedWeapon = equippedweapon;
    this->m_x = y;
    this->m_y = x;
    this->symbol = symbol;
}

void Player::move(char direction) {
    switch(direction){
        case 'w':
            m_x--;
            break;
        case 's':
            m_x++;
            break;
        case 'a':
            m_y--;
            break;
        case 'd':
            m_y++;
            break;
    }
}

void Player::print() {
    std::cout << symbol ;
}

int Player::returnX() {
    return  m_x;
}

int Player::returnY() {
    return  m_y;
}

int Player::setX(int x) {
    m_x = x;
};

int Player::setY(int y) {
    m_y = y;
};
std::string Player::getName() {
    return m_name;
}
std::string Player::getClassName() {
    return m_className;
}

int Player::getHealth() {
    return m_health;
}
int Player::getAttack() {
    return m_attack;
}
int Player::getDefence() {
    return m_defence;
}
int Player::getDexterity() {
    return m_dexterity;
}
Item* Player::getEquippedArmor() {
    return m_equippedArmor;
}
Item* Player::getEquippedWeapon() {
    return m_equippedWeapon;
}
int Player::getLevel() {
    return m_level;
}
int Player::getNextLevelXp() {
    return m_nextLevelXp;
}
int Player::getXp() {
    return m_xp;
}
int Player::getStength() {
    return m_strength;
}
std::string Player::getPlayerSymbol() {
    return symbol;
}

void Player::addItemToInventory(Item *item) {
    m_inventory.push_back(item);

};
void Player::takeDamage(int damage) {
    int damagetoTake = 0;
    if (m_defence%2 == 0){
        damagetoTake = damage -(m_defence/2);
    }
    else {damagetoTake = damage -((m_defence+1)/2);}

    damagetoTake = damagetoTake < 0 ? 0 : damagetoTake;

    m_health -= damagetoTake;
}

void Player::usePotion() {
    bool foundPotion = false;

    int i = 0;
    for(auto item: m_inventory) {
        std::string test = typeid(*item).name(); // zjištění, o jaký typ potomka se jedná

        if(test == "6Potion") {
            foundPotion = true;
            m_health+=item->getHowMuch();
            m_health = m_health > m_healthCopy ? m_healthCopy : m_health;

            m_inventory.erase(m_inventory.begin()+i);
            break;

        }

        i++;

    }

    if(!foundPotion) {
        std::cout<<std::endl;
        std::cout<<"Nemas zadny lektvar."<<std::endl;

    } else {
        std::cout<<std::endl;
        std::cout<<"Pouzil jsi lektvar. Tvuj aktualni zivot je: "<< m_health;

        i = 0;
        for(auto item: m_inventory) {
            std::string test = typeid(*item).name(); // zjištění, o jaký typ potomka se jedná

            if(test == "6Potion") {
                i++;

            }

        }
        std::cout<<". Pocet lektvaru v inventari: " <<i<<std::endl;

    }
}

int Player::checkInventorySize(char whatToEquip) {
    int i = 0;
    if(whatToEquip == 'z') {
        for(auto weapon: m_inventory) {
            std::string test = typeid(*weapon).name(); // zjištění, o jaký typ potomka se jedná

            if(test == "6Weapon") {
                i++;

            }

        }
    } else {
        for(auto armor: m_inventory) {
            std::string test = typeid(*armor).name(); // zjištění, o jaký typ potomka se jedná

            if(test == "5Armor") {
                i++;

            }

        }

    }

    return i;
}

bool Player::checkOfItemNum(int itemNum, char whatToEquip) {
    int i = 0;
    if(whatToEquip == 'z') {
        for(auto weapon: m_inventory) {
            std::string test = typeid(*weapon).name(); // zjištění, o jaký typ potomka se jedná

            if(test == "6Weapon") {
                i++;

            }

        }
    } else {
        for(auto armor: m_inventory) {
            std::string test = typeid(*armor).name(); // zjištění, o jaký typ potomka se jedná

            if(test == "5Armor") {
                i++;

            }

        }

    }

    if(itemNum < 0 || itemNum > i) {
        return false;
    }

    return true;
};

void Player::addExperience(int xpFromMonster) {
    m_xp += xpFromMonster;
    if(m_xp > m_nextLevelXp){
        m_xp -= m_nextLevelXp;
        m_level++;
        m_nextLevelXp *= 2;
        m_dexterity += 4;
        m_health += 4;
        m_strength += 4;
        m_attack += 4;
        m_defence += 4;
        std::cout << "Dosazeni "<< m_level<<". urovne."<< std::endl;
    }
}