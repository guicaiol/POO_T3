/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "field.h"

/** STATIC INFO *************************************/

// Field size
int Field::_x = 50;
int Field::_y = 50;

// Teams initial position
Position Field::_teamPos[] = {
    Position(2,2),
    Position(Field::_x-2, Field::_y-2),
    Position(Field::_x-2, 2),
    Position(2, Field::_y-2)
};

/** *************************************************/

Field::Field() {

}

void Field::reset() {
    _teams.clear();
}

void Field::addTeam(Team *team) {
    _teams.push_back(team);
}

Character* Field::getNearestEnemy(Team *team, Character *ch) {
    int min=9999;
    Character *chMin=NULL;

    _fieldAccess.lock();

    // For each team
    MyVector<Team*>::iterator it1;
    for(it1=_teams.begin(); it1!=_teams.end(); it1++) {
        Team *t = *it1;

        // Not my team
        if(t==team)
            continue;

        // For each player
        const std::vector<Character*> *characters = t->chars();
        std::vector<Character*>::const_iterator it2;
        for(it2=characters->cbegin(); it2!=characters->cend(); it2++) {
            Character *enemy = *it2;

            // Only alive
            if(enemy->isAlive()==false)
                continue;

            // Calc distance and get min
            int dist = ch->getPosition().distanceTo(enemy->getPosition());
            if(dist<min) {
                min = dist;
                chMin = enemy;
            }
        }
    }

    _fieldAccess.unlock();

    return chMin;
}
