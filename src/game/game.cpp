/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "game.h"

Game::Game(int rounds, int roundTime) {
    _rounds = rounds;
    _roundTime = roundTime;
}

void Game::addTeam(Team *team) {
    // Check pointer
    if(team==NULL)
        throw std::invalid_argument("Game::addTeam(Team* team), team is NULL pointer!");

    // Check if already is added
    if(_teams.contains(team))
        throw std::runtime_error("Game::addTeam(Team* team), team is already on Game!");

    // Check number of teams // max=4
    if(_teams.size()==4)
        throw std::runtime_error("Game::addTeam(Team* team), maximum of 4 teams per game reached!");

    // Add
    _teams.push_back(team);
}

void Game::loop() {

    // Check number of teams, has to be at least 2
    if(_teams.size()<2)
        throw std::runtime_error("Game::run(), game can only start with at least 2 teams!");

    // Run rounds
    for(int round=1; round<=_rounds; round++) {
        std::vector<Team*>::iterator it;
        int c=0;
        std::cout << "Starting round #" << round << "...\n";

        // For each team, do reset operations
        c=0;
        for(it=_teams.begin(); it!=_teams.end(); it++,c++) {
            Team *team = *it;
            // Stop characteres, case some of them stayed as winner of previous round
            team->stopBattle();

            // Reset team characters
            team->reset();

            // Set initial positions
            team->setInitialPosition(Field::teamPos(c));
        }

        // For each team, start game!
        c=0;
        for(it=_teams.begin(); it!=_teams.end(); it++,c++) {
            Team *team = *it;
            team->startGame();
            std::cout << "Team '" << team->getName() << "' is on battle!\n";
        }

        // Wait until only one team is alive, or timeout
        Timer timer;
        timer.start();
        while(true) {
            msleep(20);

            // Check teams alive (a team with playersAlive>0 is an alive team)
            int teamsAlive=0;
            for(it=_teams.begin(); it!=_teams.end(); it++) {
                Team *team = *it;
                if(team->playersAlive()>0)
                    teamsAlive++;
            }
            if(teamsAlive<=1) // we have a winner (1), or draw (0)
                break;

            // Time out
            timer.mark();
            if(timer.timesec()>=_roundTime) { // time out!
                std::cout << "TIME OUT!\n";
                stopBattle();
                break;
            }
        }

        // Announce round winner
        std::cout << "End of round #" << round << ", result: ";
        Team* winner = resolveBattle();
        if(winner==NULL)
            std::cout << "DRAW!";
        else
            std::cout << "'" << winner->getName() << "' wins!";
        std::cout << std::endl;
    }

    // For each team, do final reset operations
    int c=0;
    std::vector<Team*>::iterator it;
    for(it=_teams.begin(); it!=_teams.end(); it++,c++) {
        Team *team = *it;

        // Stop characters
        team->stopBattle();

        // Reset team characters
        team->reset();
    }

    stop();
}

void Game::stopBattle() {
    // Stop each team
    std::vector<Team*>::iterator it;
    for(it=_teams.begin(); it!=_teams.end(); it++) {
        Team *team = *it;
        team->stopBattle();
    }
}

Team* Game::resolveBattle() {
    double max = -1;
    Team *win=NULL;

    // Get team with max points; if two teams with same result, its a draw!
    std::vector<Team*>::iterator it;
    for(it=_teams.begin(); it!=_teams.end(); it++) {
        Team *team = *it;
        double points = team->getPoints();
        if(points>max) { // winner
            win = team;
            max = points;
        } else if(points==max)
            win = NULL; // draw
    }
    return win;
}
