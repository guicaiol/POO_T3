/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef GAME_H
#define GAME_H

#include <exception>
#include "src/utils/thread.h"
#include "src/utils/myvector.h"
#include "src/utils/timer.h"
#include "src/team/team.h"
#include "field.h"

class Game : public Thread {
public:
    Game(int rounds = 3, int roundTime = 120);

    // Adds a team to the game
    void addTeam(Team *team);
private:
    // Number of rounds in this game
    int _rounds;

    // Duration (seconds) of a round
    int _roundTime;

    // List of teams in the game
    MyVector<Team*> _teams;

    // Inherit from Thread, implements the thread function
    void loop();

    // Stop team players threads
    void stopBattle();

    // Resolve battle, adding win/lose/draw to teams and returning winner
    Team* resolveBattle();
};

#endif // GAME_H
