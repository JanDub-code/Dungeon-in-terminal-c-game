//
// Created by cicva on 12/6/2022.
//

#include "Combat.h"

Combat::Combat() {}

bool Combat::engage(Player *player, Enemy *monster) {
    bool fightLoop = true;
    int turn = 0;
    char playerInput;
    std::cout << "Boj:" << std::endl;
    while (fightLoop == true) {
        if(player->isDead() != true and monster->isDead() != true){
            if (turn%2 == 0){
                displayCombatText(player,monster);
                std::cin >> playerInput;
                switch(playerInput) {
                    case 'a':
                        std::cout <<"Hrac utoci" << std::endl;
                        monster->takeDamage(player->getAttack());
                        break;
                    case 'd':
                        std::cout <<"Hrac pripravuje na obranu" << std::endl;
                        Combat::halfHit(player,monster);
                        turn++;
                        break;
                    case 'e':
                        Combat::halfHit(player,monster);
                        fightLoop = false;
                        break;

                    case 'u':
                          player->usePotion();
                        break;

                    default:
                        std::cout <<"Spatna klavesa se tresta!" << std::endl;
                        break;

                }
                if(playerInput != 'u') {
                    turn++;
                }

            }
            else{
                std::cout << "Nepritel utoci" << std::endl;
                Combat::fullHit(player,monster);
                turn++;

            }

            }
        if(monster->isDead() == true){player->addExperience(monster->getDroppedExp());fightLoop = false;}
        else if(player->isDead() == true){fightLoop = false;}

    }
    Combat::displayCombatResult(player,monster);
    return player->isDead();
}
void Combat::fullHit(Player *player, Enemy *monster) {
    player->takeDamage(monster->getStrength());
}
void Combat::halfHit(Player *player, Enemy *monster) {
    if (monster->getStrength()%2 == 0 ){
        player->takeDamage((monster->getStrength()/2));
    }
    else{
    player->takeDamage(((monster->getStrength()-1)/2));
    }
}
void Combat::displayCombatText(Player *player, Enemy *monster) {
    std::cout <<"\nTvuj aktualni zivot: " <<  player->getHealth() << std::endl;
    std::cout <<"Aktualni zivot protivnika: " <<  monster->getHealth() << std::endl;
    std::cout <<"Utok: a, Obrana: d, Utek: e, Pouzit lecivy lektvar: u" << std::endl;
}
void Combat::displayCombatResult(Player *player, Enemy *monster) {
    if(monster->isDead() == true){
        std::cout << "Nepritel zemrel\n" <<std::endl;
        std::cout << "Hracuv zivot po tomto boji: "<<player->getHealth() <<std::endl;
        std::cout << "Aktualni pocet zkusenosti: "<< player->getXp()<< std::endl;
        std::cout << "Zkusenosti potrebne pro dosazeni dalsi urovne: "<<player->getNextLevelXp() <<"\n" << std::endl;

    }
    else if (player->isDead() == true){
        std::cout << "Hrac zemrel\n" << std::endl;

    }
    else{
        std::cout << "Hrac utekl" << std::endl;
        std::cout <<"Tvuj aktualni zivot:"  <<  player->getHealth() <<"\n"<< std::endl;
    }
}