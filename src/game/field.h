/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include <assert.h>
#include "src/utils/position.h"

class Field  {
public:
    static int x() { return Field::_x; }
    static int y() { return Field::_y; }

    static Position teamPos(int index) { assert(index<4); return Field::_teamPos[index]; }
private:
    static int _x;
    static int _y;

    static Position _teamPos[4];
};
