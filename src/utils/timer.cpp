/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "timer.h"

Timer::Timer() {
    reset();
}

void Timer::reset() {
    time1.tv_sec = time1.tv_nsec = 0;
    time2.tv_sec = time2.tv_nsec = 0;
}

void Timer::start() {
    clock_gettime(CLOCK_REALTIME, &time1);
}

void Timer::mark() {
    clock_gettime(CLOCK_REALTIME, &time2);
}

long Timer::timesec() {
    return time2.tv_sec-time1.tv_sec;
}

long Timer::timemsec()	{
    return timesec()*1E3+timeusec()/1E3;
}

long Timer::timeusec()	{
    return timensec()/1E3;
}

long Timer::timensec()	{
    return time2.tv_nsec-time1.tv_nsec;
}
