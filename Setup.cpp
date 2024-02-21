//
// Created by Johny on 15.01.2023.
//

#include "Setup.h"
#include "Item.h"
#include "Tile.h"
#include "MapMatrix.h"
#include "AverageEnemy.h"
#include "ItemFactory.h"
#include "Player.h"
#include "SmallEnemy.h"
#include "HugeEnemy.h"
#include "EnemyFactory.h"
#include "EasyEnemyFactory.h"
#include "MediumEnemyFactory.h"
#include "HardEnemyFactory.h"
#include "Combat.h"
int Item::m_id = 0;

bool Setup::setUpAll() {
    char playerdecision;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Pro zacatek nove hry stiskni 1" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Pro konec stiskni 2" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cin >> playerdecision;
    while ((playerdecision != '1' and playerdecision != '2')) {
        std::cout << "Spatna volba. Zkuste to prosim znova"<<std::endl;
        std::cin >> playerdecision;
    }
    if (playerdecision == '1') {
        char difficulty; // testovani volby obtiznosti 1 easy,2 medium,3 hard
        std::cout << "Vyber obtiznost: (1-lehka, 2-stredni, 3-tezka)";
        std::cin >> difficulty;
        while ((difficulty != '1' and difficulty != '2' and difficulty != '3')) {
            std::cout << "Spatna volba. Zkuste to prosim znova"<<std::endl;
            std::cin >> difficulty;
        }
        EnemyFactory *ef = nullptr;
        switch (difficulty) {
            case '1':
                ef = new EasyEnemyFactory();
                break;
            case '2':
                ef = new MediumEnemyFactory();
                break;
            case '3':
                ef = new HardEnemyFactory();
                break;

        }

        Combat* combat = new Combat();
        SmallEnemy* skeleton1 = ef->getSmallEnemy();
        SmallEnemy* skeleton2 = ef->getSmallEnemy();
        SmallEnemy* skeleton3 = ef->getSmallEnemy();
        SmallEnemy* skeleton4 = ef->getSmallEnemy();
        SmallEnemy* skeleton5 = ef->getSmallEnemy();
        SmallEnemy* skeleton6 = ef->getSmallEnemy();
        SmallEnemy* skeleton7 = ef->getSmallEnemy();
        AverageEnemy* zombie1 = ef->getAverageEnemy();
        AverageEnemy* zombie2 = ef->getAverageEnemy();
        HugeEnemy* ogre = ef->getHugeEnemy();

        Tile * tileWithSkeleton1= new Tile("M");
        Tile * tileWithSkeleton2= new Tile("M");
        Tile * tileWithSkeleton3= new Tile("M");
        Tile * tileWithSkeleton4= new Tile("M");
        Tile * tileWithSkeleton5= new Tile("M");
        Tile * tileWithSkeleton6= new Tile("M");
        Tile * tileWithSkeleton7= new Tile("M");
        Tile * tileWithZombie1= new Tile("M");
        Tile * tileWithZombie2= new Tile("M");
        Tile * tileWithOgre = new Tile("M");

        tileWithSkeleton1->setEnemies(skeleton1);
        tileWithSkeleton2->setEnemies(skeleton2);
        tileWithSkeleton3->setEnemies(skeleton3);
        tileWithSkeleton4->setEnemies(skeleton4);
        tileWithSkeleton5->setEnemies(skeleton5);
        tileWithSkeleton6->setEnemies(skeleton6);
        tileWithSkeleton7->setEnemies(skeleton7);
        tileWithZombie1->setEnemies(zombie1);
        tileWithZombie2->setEnemies(zombie2);
        tileWithOgre->setEnemies(ogre);

        Player* joker = new Player(2,2,"P");
        joker->createClass();
        joker->viewStatistics('t');
        int x = joker->returnX();
        int y = joker->returnY();


        Item* lightSword = (new ItemFactory)->createWeapon("Lehky mec", 5);
        Item* heavyAxe = (new ItemFactory)->createWeapon("Tezka sekera", 15);

        Item* chainArmor = (new ItemFactory)->createArmor("Retizkova zbroj", 10);
        Item* metalArmor = (new ItemFactory)->createArmor("Kovova zbroj", 15);

        Item* healthPot = (new ItemFactory)->createPotion("Lecivy lektvar", "zivot", 20);

        Tile * swordTile = new Tile(lightSword->getAppereance());
        swordTile->setItems(lightSword);
        Tile * axeTile = new Tile(heavyAxe->getAppereance());
        axeTile->setItems(heavyAxe);

        Tile * chainTile = new Tile(chainArmor->getAppereance());
        chainTile->setItems(chainArmor);
        Tile * metalTile = new Tile(metalArmor->getAppereance());
        metalTile->setItems(metalArmor);

        Tile * healthPotTile = new Tile(healthPot->getAppereance());
        healthPotTile->setItems(healthPot);
        Tile * healthPotTile2 = new Tile(healthPot->getAppereance());
        healthPotTile2->setItems(healthPot);
        Tile * healthPotTile3 = new Tile(healthPot->getAppereance());
        healthPotTile3->setItems(healthPot);
        Tile * healthPotTile4 = new Tile(healthPot->getAppereance());
        healthPotTile4->setItems(healthPot);
        Tile * healthPotTile5 = new Tile(healthPot->getAppereance());
        healthPotTile5->setItems(healthPot);
        Tile * healthPotTile6 = new Tile(healthPot->getAppereance());
        healthPotTile6->setItems(healthPot);
        Tile * healthPotTile7 = new Tile(healthPot->getAppereance());
        healthPotTile7->setItems(healthPot);
        Tile * healthPotTile8 = new Tile(healthPot->getAppereance());
        healthPotTile8->setItems(healthPot);

        MapMatrix*mapMatrix=new MapMatrix(5,5);

        Map*map = new Map(5, 5);
        Map*map2=new Map(9,5);
        Map*map3=new Map(6,6);
        Map*map4=new Map(6,6);
        Map*map5=new Map(9,5);
        Map*map6=new Map(7,7);
        Map*map7=new Map(5,5);
        Map*map8=new Map(5,5);
        Map*map9=new Map(5,5);
        Map*map10=new Map(5,5);

        map->setNewAppearance(x, y, "P");
        map->setNewAppearance(2, 4, "D");
        map->setNewAppearance(4,2,"D");

        map->setValue(2, 3, tileWithSkeleton1);

        map->setValue(1, 1, swordTile);


        map2->setNewAppearance(2,0,"D");
        map2->setNewAppearance(2,8,"D");
        map2->setNewAppearance(1,4,"#");
        map2->setNewAppearance(2,4,"#");
        map2->setNewAppearance(3,4,"#");
        map2->setValue(1, 3, healthPotTile);
        map2->setValue(1, 5, chainTile);
        map2->setValue(3, 5, axeTile);

        map3->setNewAppearance(0,3,"D");
        map3->setNewAppearance(3,5,"D");
        map3->setNewAppearance(5,3,"D");
        map3->setValue(3, 3, tileWithSkeleton2);

        map4->setNewAppearance(0,2,"D");
        map4->setValue(4, 4, healthPotTile2);
        map4->setValue(4, 1, healthPotTile3);
        map4->setValue(2, 2, tileWithSkeleton3);


        map5->setNewAppearance(2,0,"D");
        map5->setNewAppearance(2,8,"D");
        map5->setNewAppearance(1,3,"#");
        map5->setNewAppearance(3,3,"#");
        map5->setValue(3, 6, healthPotTile4);
        map5->setValue(2, 3, tileWithZombie1);

        map6->setNewAppearance(3,0,"D");
        map6->setNewAppearance(0,3,"D");
        map6->setNewAppearance(3,6,"D");
        map6->setNewAppearance(6,3,"D");
        map6->setValue(2, 2, healthPotTile5);
        map6->setValue(3, 5, tileWithSkeleton4);
        map6->setValue(5, 3, tileWithSkeleton5);

        map7->setNewAppearance(2,0,"D");
        map7->setNewAppearance(4,2,"D");
        map7->setValue(1, 2, healthPotTile6);

        map8->setNewAppearance(0,2,"D");
        map8->setNewAppearance(4,2,"D");
        map8->setValue(1, 1, healthPotTile7);
        map8->setValue(3, 3, healthPotTile8);
        map8->setValue(2, 3, tileWithSkeleton6);
        map8->setValue(3, 2, tileWithZombie2);

        map9->setNewAppearance(2,0,"D");
        map9->setValue(2,2,tileWithSkeleton7);
        map9->setValue(1, 2, metalTile);

        map10->setNewAppearance(0,2,"D");
        map10->setValue(2, 2, tileWithOgre);


        mapMatrix->setValue(1,1,map);
        mapMatrix->setValue(2,1,map2);
        mapMatrix->setValue(1,2,map3);
        mapMatrix->setValue(1,3,map4);
        mapMatrix->setValue(2,2,map5);
        mapMatrix->setValue(3,2,map6);
        mapMatrix->setValue(3,1,map7);
        mapMatrix->setValue(3,3,map8);
        mapMatrix->setValue(4,2,map9);
        mapMatrix->setValue(3,4,map10);

        bool endLoop = false;
        mapMatrix->getValue(1,1)->print();
        int mapPositionX=1;
        int mapPositionY=1;
        while(endLoop == false)
        {
            char playerInput;
            std::cout<<std::endl;
            std::cout<<"Zadej jednu z klaves:"<<std::endl;
            std::cout<<"Pro pohyb hrace: (w/a/s/d)" <<std::endl;
            std::cout<<"Pro zobrazeni statistik: t" <<std::endl;
            std::cout<<"Pro zobrazeni inventare: i" <<std::endl;
            std::cout<<"Pro doplneni zdravy: u" <<std::endl;
            std::cout<<"Pro pouziti zbrane/brneni z inventare: e" <<std::endl;
            std::cout<<"Pro konec hry: k" <<std::endl;
            std::cin>>playerInput;

            if(playerInput == 'k') {
                std::cout<<"Dekujeme za zahrani nasi hry. Nashledanou."<<std::endl;
                endLoop = true;
                break;

            };
            mapMatrix->getValue(mapPositionX,mapPositionY)->setNewAppearance(x,y,"P");
            joker->move(playerInput);
            int x2 = joker->returnX();
            int y2 = joker->returnY();

            if(mapMatrix->getValue(mapPositionX,mapPositionY)->getValue(x2,y2)->getAppearance() == "#") {
                joker->setX(x);
                joker->setY(y);
                for(int i = 0;i<=50;i++){std::cout <<std::endl;}
            } else if (mapMatrix->getValue(mapPositionX,mapPositionY)->getValue(x2,y2)->getAppearance() == "D") {
                //endLoop = true;
                switch(playerInput){
                    case 'w': {
                        mapMatrix->getValue(mapPositionX, mapPositionY)->setNewAppearance(x, y, " ");
                        mapPositionY--;
                        int lenght = mapMatrix->getValue(mapPositionX, mapPositionY)->getWidth();
                        int height = mapMatrix->getValue(mapPositionX, mapPositionY)->getHeight();

                        for (int j = 0; j <lenght ; ++j) {
                            if (mapMatrix->getValue(mapPositionX, mapPositionY)->getValue(height-1,
                                                                                          j)->getAppearance() ==
                                "D") {
                                joker->setX(height-2);
                                joker->setY(j);
                            }
                        }
                        mapMatrix->getValue(mapPositionX, mapPositionY)->setNewAppearance(x, y, "P");

                        break;
                    }
                    case 's': {
                        mapMatrix->getValue(mapPositionX, mapPositionY)->setNewAppearance(x, y, " ");
                        mapPositionY++;
                        int lenght = mapMatrix->getValue(mapPositionX, mapPositionY)->getWidth();

                        for (int j = 0; j < lenght; ++j) {
                            if (mapMatrix->getValue(mapPositionX, mapPositionY)->getValue(0,
                                                                                          j)->getAppearance() ==
                                "D") {
                                joker->setX(0 + 1);
                                joker->setY(j);
                            }
                        }

                        mapMatrix->getValue(mapPositionX, mapPositionY)->setNewAppearance(x, y, "P");
                        break;
                    }
                    case 'a': {
                        mapMatrix->getValue(mapPositionX, mapPositionY)->setNewAppearance(x, y, " ");
                        mapPositionX--;
                        int lenght = mapMatrix->getValue(mapPositionX, mapPositionY)->getWidth();
                        int height = mapMatrix->getValue(mapPositionX, mapPositionY)->getHeight();
                        for (int i = 0; i < height; ++i) {

                            if (mapMatrix->getValue(mapPositionX, mapPositionY)->getValue(i,
                                                                                          lenght-1)->getAppearance() ==
                                "D") {
                                joker->setX(i);
                                joker->setY(lenght-2);
                            }
                        }
                        mapMatrix->getValue(mapPositionX, mapPositionY)->setNewAppearance(x, y, "P");
                        break;
                    }
                    case 'd': {
                        mapMatrix->getValue(mapPositionX, mapPositionY)->setNewAppearance(x, y, " ");
                        mapPositionX++;
                        int height = mapMatrix->getValue(mapPositionX, mapPositionY)->getHeight();
                        for (int i = 0; i < height; ++i) {
                            for (int j = 0; j < 1; ++j) {
                                if (mapMatrix->getValue(mapPositionX, mapPositionY)->getValue(i,
                                                                                              j)->getAppearance() ==
                                    "D") {
                                    joker->setX(i);
                                    joker->setY(j + 1);
                                }
                            }
                        }
                        mapMatrix->getValue(mapPositionX, mapPositionY)->setNewAppearance(x, y, "P");
                        break;
                    }
                }

                mapMatrix->getValue(mapPositionX,mapPositionY)->setNewAppearance(x,y," ");
                x = joker->returnX();
                y = joker->returnY();
                mapMatrix->getValue(mapPositionX,mapPositionY)->setNewAppearance(x,y,"P");
                for(int i = 0;i<=50;i++){std::cout <<std::endl;}
            }
            else if(mapMatrix->getValue(mapPositionX,mapPositionY)->getValue(x2,y2)->getAppearance() != "D" && mapMatrix->getValue(mapPositionX,mapPositionY)->getValue(x2,y2)->getAppearance() != "P" && mapMatrix->getValue(mapPositionX,mapPositionY)->getValue(x2,y2)->getAppearance() != "M" && mapMatrix->getValue(mapPositionX,mapPositionY)->getValue(x2,y2)->getAppearance() != " "){
                for(int i = 0;i<=50;i++){std::cout <<std::endl;}

                std::cout<<"Sebral jsi novou vec: "<<mapMatrix->getValue(mapPositionX,mapPositionY)->getValue(x2,y2)->getItems().at(0)->getName()<<std::endl<<std::endl;
                mapMatrix->getValue(mapPositionX,mapPositionY)->setNewAppearance(x,y," ");

                joker->addItemToInventory((new ItemFactory)->createItemCopy(mapMatrix->getValue(mapPositionX,mapPositionY)->getValue(x2,y2)->getItems().at(0)));

                x = joker->returnX();
                y = joker->returnY();
                mapMatrix->getValue(mapPositionX,mapPositionY)->setNewAppearance(x,y,"P");
            }
            else if(mapMatrix->getValue(mapPositionX,mapPositionY)->getValue(x2,y2)->getAppearance() == "M") {
                for(int i = 0;i<=50;i++){std::cout <<std::endl;}
                combat->engage(joker,mapMatrix->getValue(mapPositionX,mapPositionY)->getValue(x2,y2)->getEnemies().at(0));
                if(joker->isDead() == true){
                    std::cout <<"--------Konec hry--------" << std::endl;
                    break;
                }
                else if(ogre->isDead() == true){
                    std::cout <<"--------Vyhrali jste--------" << std::endl;
                    std::cout <<"Dekujeme za zahrani nasi hry" << std::endl;
                    break;
                }
                else if (mapMatrix->getValue(mapPositionX,mapPositionY)->getValue(x2,y2)->getEnemies().at(0)->isDead() == false){
                    mapMatrix->getValue(mapPositionX,mapPositionY)->setNewAppearance(x,y,"P");
                    //mapMatrix->getValue(mapPositionX,mapPositionY)->setNewAppearance(x,y,"P");
                    joker->setX(x);
                    joker->setY(y);
                }
                else{
                    mapMatrix->getValue(mapPositionX,mapPositionY)->setNewAppearance(x,y," ");
                    x = joker->returnX();
                    y = joker->returnY();
                    mapMatrix->getValue(mapPositionX,mapPositionY)->setNewAppearance(x,y,"P");
                }
            }

            else {
                mapMatrix->getValue(mapPositionX,mapPositionY)->setNewAppearance(x,y," ");
                x = joker->returnX();
                y = joker->returnY();
                mapMatrix->getValue(mapPositionX,mapPositionY)->setNewAppearance(x,y,"P");
                if(playerInput != 'e') {for(int i = 0;i<=50;i++){std::cout <<std::endl;}}
            }

            if(playerInput == 'e') {
                while(playerInput == 'e') {
                    char whatToEquip;
                    if(whatToEquip != 'z' && whatToEquip != 'b'){std::cout<<"Co chcete z inventare pouzit? Zbran: z, Brneni: b"<<std::endl;}

                    if(whatToEquip != 'z' && whatToEquip != 'b'){
                        std::cin>>whatToEquip;
                    }

                    if(whatToEquip != 'z' && whatToEquip != 'b') {
                        playerInput = 'i';
                        whatToEquip = 'i';

                    } else {
                        joker->viewSeparateInventory(whatToEquip);
                        int itemNum;
                        if(whatToEquip == 'b') {
                            if(joker->checkInventorySize(whatToEquip) > 0) {
                                std::cout<<"Jakou zbroj chcete pouzit? Zadejte cislo v poradi."<<std::endl;
                                std::cin>>itemNum;
                                while(!joker->checkOfItemNum(itemNum, whatToEquip) && itemNum != 9999) {
                                    std::cout<<"V tomto poradi neni zadna zbroj. Zadejte cislo znova"<<std::endl;
                                    std::cin>>itemNum;

                                }
                                if(itemNum != 9999) {joker->equippArmor(itemNum);}

                            } else {
                                std::cout<<"Nemate zadne brneni v inventari."<<std::endl<<std::endl;

                            }

                            playerInput = 'x';
                            whatToEquip = 'i';
                        } else {
                            if(joker->checkInventorySize(whatToEquip) > 0) {
                                std::cout << "Jakou zbran chcete pouzit? Zadejte cislo v poradi." << std::endl;

                                std::cin >> itemNum;
                                while (!joker->checkOfItemNum(itemNum, whatToEquip) && itemNum != 9999) {
                                    std::cout << "V tomto poradi neni zadna zbran. Zadejte cislo znova"
                                              << std::endl;
                                    std::cin >> itemNum;

                                }
                                if (itemNum != 9999) { joker->equippWeapon(itemNum); }

                            } else {
                                std::cout<<"Nemate zadnou zbran v inventari."<<std::endl<<std::endl;

                            }

                            playerInput = 'x';
                            whatToEquip = 'i';

                        }


                    }
                }
            }

            mapMatrix->getValue(mapPositionX,mapPositionY)->print();

            joker->viewStatistics(playerInput);
            joker->viewInventory(playerInput);

            if(playerInput == 'u') {
                joker->usePotion();
            }



        }

        delete chainArmor;
        delete lightSword;
        delete joker;
        delete skeleton1;
        delete skeleton2;
        delete skeleton3;
        delete skeleton4;
        delete skeleton5;
        delete skeleton6;
        delete skeleton7;
        delete zombie1;
        delete zombie2;
        delete ogre;
        delete combat;

        return false;

    } else if (playerdecision == '2') {
        std::cout << "Prejeme hezky den. Nashledanou.";
        return false;
    }

}