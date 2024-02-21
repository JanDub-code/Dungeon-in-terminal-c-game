cmake_minimum_required(VERSION 3.23)
project(ZOO_projekt)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ZOO_projekt
        Weapon.cpp Weapon.h Armor.cpp Armor.h main.cpp Player.cpp Player.h EnemyFactory.cpp EnemyFactory.h EasyEnemyFactory.cpp EasyEnemyFactory.h MediumEnemyFactory.cpp MediumEnemyFactory.h HardEnemyFactory.cpp HardEnemyFactory.h SmallEnemy.cpp SmallEnemy.h AverageEnemy.cpp AverageEnemy.h HugeEnemy.cpp HugeEnemy.h Map.cpp Map.h Tile.cpp Tile.h MapMatrix.cpp MapMatrix.h SaveAndLoad.cpp SaveAndLoad.h Item.cpp Item.h Potion.cpp Potion.h ItemFactory.cpp ItemFactory.h Enemy.cpp Enemy.h Combat.cpp Combat.h Setup.cpp Setup.h)
