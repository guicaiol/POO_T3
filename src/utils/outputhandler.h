/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef OUTPUTHANDLER_H
#define OUTPUTHANDLER_H

#include <iostream>
#include <mutex>

class OutputHandler {
private:
    static std::mutex _mutex;
public:
    static void lock();
    static void unlock();
};

#endif // OUTPUTHANDLER_H
