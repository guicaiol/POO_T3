/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include <assert.h>
#include "../team/team.h"
#include "../utils/myvector.h"
#include "../utils/position.h"

class Field  {
public:
    Field();

    // Static methods
    static int x() { return Field::_x; }
    static int y() { return Field::_y; }
    static Position teamPos(int index) { assert(index<4); return Field::_teamPos[index]; }

    // Modifiers
    void reset();
    void addTeam(Team *team);

    // Get neares enemy from team
    Character* getNearestEnemy(Team *team, Character *ch);
private:
    std::mutex _fieldAccess;

    // Static infos
    static int _x;
    static int _y;
    static Position _teamPos[4];

    // Game info
    std::vector<Team*> _teams;
};
