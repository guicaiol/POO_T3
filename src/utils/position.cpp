/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "position.h"

Position::Position() {
    setPosition(0, 0);
}

Position::Position(int x, int y) {
    setPosition(x, y);
}

void Position::setPosition(int x, int y) {
    _x = x;
    _y = y;
}

int Position::distanceTo(const Position &position) {
    return (int)sqrt(pow(position.x()-_x,2) + pow(position.y()-_y,2));
}
