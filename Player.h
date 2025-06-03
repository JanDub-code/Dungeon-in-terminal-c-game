//
// Created by Workstation on 11.11.2022.
//

#ifndef ZOO_PROJEKT_PLAYER_H
#define ZOO_PROJEKT_PLAYER_H

#include <string>
#include <vector>
#include "Armor.h"
#include "Weapon.h"

class Player {
private:
    int m_health;
    int m_healthCopy;
    int m_strength;
    int m_dexterity;
    int m_level;
    std::string m_name;
    std::string m_className;
    int m_xp;
    int m_nextLevelXp;
    int m_attack;
    int m_defence;
    int m_attackCopy;
    int m_defenceCopy;
    bool m_isDead = false;
    Item* m_equippedArmor;
    Item* m_equippedWeapon;
    int m_x;
    int m_y;
    std::string symbol;
    std::vector<Item *> m_inventory;
    // inventář

public:
    Player(int x, int y, std::string symbol);
    Player();
    Player(int health,int strength,int dexterity,int level,std::string name,std::string classname,int xp,int nextlevelxp,
           int attack,int defence,Item* equippedarmor,Item* equippedweapon,int x,int y,std::string symbol);

    void move(char direction);
    void print();
    int returnX();
    int returnY();
    void setX(int x);
    void setY(int y);
    bool isDead();
    void equippArmor(int armorItem);
    void equippWeapon(int weaponItem);
    void takeDamage(int damage);
    void createClass();
    void viewStatistics(char input);
    void viewInventory(char input);

    std::string getName();
    int getHealth();
    int getStength();
    int getDexterity();
    int getLevel();
    std::string getClassName();
    int getXp();
    int getNextLevelXp();
    int getAttack();
    int getDefence();
    Item* getEquippedArmor();
    Item* getEquippedWeapon();
    std::string getPlayerSymbol();
    void addItemToInventory(Item *item);
    bool checkOfItemNum(int itemNum, char whatToEquip);
    void usePotion();
    int checkInventorySize(char whatToEquip);
    void addExperience(int xpFromMonster);
    void viewSeparateInventory(char input);

};


#endif //ZOO_PROJEKT_PLAYER_H
