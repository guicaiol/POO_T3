/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "field.h"

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
