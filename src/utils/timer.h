/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef TIMER_H
#define TIMER_H

#include <ctime>

class Timer {
public:
    Timer();

    void reset();
    void start();
    void mark();
    long timesec();
    long timemsec();
    long timeusec();
    long timensec();
private:
    timespec time1, time2;
};

#endif // TIMER_H
