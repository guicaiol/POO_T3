/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef GAME_H
#define GAME_H

#include <exception>
#include "../utils/thread.h"
#include "../utils/myvector.h"
#include "../utils/timer.h"
#include "../utils/outputhandler.h"
#include "../team/team.h"
#include "field.h"

class Game : public Thread {
public:
    Game(int rounds = 3, int roundTime = 120);
    virtual ~Game();

    // Adds a team to the game
    void addTeam(Team *team);
private:
    // Number of rounds in this game
    int _rounds;

    // Duration (seconds) of a round
    int _roundTime;
    int _marker;

    // List of teams in the game
    MyVector<Team*> _teams;

    // Field with characters information
    Field _field;

    // Inherit from Thread, implements the thread function
    void loop();

    // Stop team players threads
    void generateField();
    void resetBattle();
    void stopBattle();
    void startBattle();

    // Resolve round/battle and return winner
    Team* resolveRound();
    Team* resolveBattle();

};

#endif // GAME_H
