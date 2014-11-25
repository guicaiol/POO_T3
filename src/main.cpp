/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include <iostream>
#include "src/game/game.h"

#include "src/character/characters.h"

int main() {

    Team t1("T1", blue);
    t1.addChar(new Wizard("t1c1", 10));

    Team t2("T2", yellow);
    t2.addChar(new Thief("t2c1", 10));

    Game game(2, 5);
    game.addTeam(&t1);
    game.addTeam(&t2);

    game.start();
    game.wait();


    return 0;
}

