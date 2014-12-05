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
    _marker = -1;
}

Game::~Game() {
    std::vector<Team*>::iterator it;
    for(it=_teams.begin(); it!=_teams.end(); it++) {
        Team *team = *it;
        delete team;
    }
    _teams.clear();
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

void flushstdin() {
    int c;
    do {
        c = getchar();
    } while (c!='\n' && c!=EOF);
}

void Game::loop() {
    flushstdin();

    // Check number of teams, has to be at least 2
    if(_teams.size()<2)
        throw std::runtime_error("Game::run(), game can only start with at least 2 teams!");

    // Initialize teams with field information
    generateField();

    std::cout << "\n---- Preparar para a batalha ----\n";

    // Run rounds
    for(int round=1; round<=_rounds; round++) {
        std::vector<Team*>::iterator it;

        std::cout << "-- Round #" << round << " --\n";
        std::cout << "Pressione qualquer tecla para iniciar!";
        getchar();
        std::cout << "\n";

        // Reset battle
        resetBattle();

        // Start battle
        startBattle();

        std::cout << "\n";

        // Wait until only one team is alive, or time out
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

            // Mark time
            timer.mark();

            // Time remaining print
            int time = _roundTime-timer.timesec();
            if(time!=_marker) {
                OutputHandler::lock();
                std::cout << "Tempo restante: [" << time << " segundos]\n";
                OutputHandler::unlock();
                _marker = time;
            }

            // Time out checking
            if(timer.timesec()>=_roundTime) { // time out!
                OutputHandler::lock();
                std::cout << "TEMPO ESGOTADO!\n";
                OutputHandler::unlock();
                stopBattle();
                break;
            }
        }

        // Announce round winner
        std::cout << "Fim do round #" << round << ", resultado: ";
        Team* winner = resolveRound();
        if(winner==NULL)
            std::cout << "EMPATE!";
        else
            std::cout << winner->getName() << " ganhou (" << (int)winner->getPoints() << " pontos)!";
        std::cout << "\n\n";

        // Compute win/lose/draw
        if(winner==NULL) {
            MyVector<Team*>::iterator it;
            for(it=_teams.begin(); it!=_teams.end(); it++) {
                Team *team = *it;
                team->addDraw();
            }
        } else {
            winner->addWin();
            MyVector<Team*>::iterator it;
            for(it=_teams.begin(); it!=_teams.end(); it++) {
                Team *team = *it;
                if(team==winner)
                    continue;
                team->addLose();
            }
        }

    }

    // For each team, do final reset operations
    resetBattle();

    // Announce game winner
    std::cout << "---- Resultado da batalha ----\n";
    Team *winner = resolveBattle();
    if(winner==NULL)
        std::cout << ">> EMPATE!";
    else
        std::cout << ">> " << winner->getName() << " é o vencedor!\n";
    std::cout << "\nPressione qualquer tecla para sair.";
    getchar();
    std::cout << "\n";

    stop();
}

void Game::generateField() {
    // Clean
    _field.reset();

    // Add teams to field
    std::vector<Team*>::iterator it;
    for(it=_teams.begin(); it!=_teams.end(); it++) {
        Team *team = *it;
        _field.addTeam(team);
        team->setField(&_field);
    }
}

void Game::resetBattle() {
    // First, stop battle, for convenience
    stopBattle();

    // Then reset characters and set initial positions
    int c=0;
    std::vector<Team*>::iterator it;
    for(it=_teams.begin(); it!=_teams.end(); it++,c++) {
        Team *team = *it;
        // Reset team characters
        team->reset();

        // Set initial positions
        team->setInitialPosition(Field::teamPos(c));
    }
}

void Game::stopBattle() {
    // Stop each team
    std::vector<Team*>::iterator it;
    for(it=_teams.begin(); it!=_teams.end(); it++) {
        Team *team = *it;
        team->stopBattle();
    }
}

void Game::startBattle() {
    // Start each team
    int c=0;
    std::vector<Team*>::iterator it;
    for(it=_teams.begin(); it!=_teams.end(); it++,c++) {
        Team *team = *it;
        team->startBattle();
        std::cout << "Time " << team->getName() << " está na batalha!\n";
    }
}

Team* Game::resolveRound() {
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

Team* Game::resolveBattle() {
    double max = -1;
    Team *winner=NULL;

    // Get team with max wins; if two teams with same result, its a draw!
    std::vector<Team*>::iterator it;
    for(it=_teams.begin(); it!=_teams.end(); it++) {
        Team *team = *it;
        int win = team->getWin();
        if(win>max) { // winner
            winner = team;
            max = win;
        } else if(win==max)
            winner = NULL; // draw
    }
    return winner;
}
