/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "outputhandler.h"

std::mutex OutputHandler::_mutex;

void OutputHandler::lock() {
    OutputHandler::_mutex.lock();
}

void OutputHandler::unlock() {
    OutputHandler::_mutex.unlock();
}
