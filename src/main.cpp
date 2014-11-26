/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include <iostream>
#include "src/game/game.h"

#include "src/character/characters.h"
#include "src/item/items.h"

int main() {

    Character *c1 = new Wizard("t1c1", 10);
    c1->storeItem(new Weapon("Knife", 100, 9, 1, 10));
    c1->equipItem("Knife");
    c1->setSpeed(5);

    Character *c2 = new Wizard("t1c2", 10);
    c2->storeItem(new Weapon("Knife", 100, 9, 1, 10));
    c2->equipItem("Knife");
    c2->setSpeed(5);

    Team t1("T1", blue);
    t1.addChar(c1);
    t1.addChar(c2);

    Character *c3 = new Wizard("t2c1", 10);
    c3->storeItem(new Weapon("Knife", 100, 9, 1, 5));
    c3->equipItem("Knife");
    c3->setSpeed(5);
    c3->addXP(10);

    Team t2("T2", yellow);
    t2.addChar(c3);

    Game game(1, 20);
    game.addTeam(&t1);
    game.addTeam(&t2);

    game.start();
    game.wait();


    return 0;
}
