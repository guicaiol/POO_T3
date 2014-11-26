/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "thread.h"

Thread::Thread() {
    _running = false;
    _enabled = true;
}

void Thread::start() {
    if(_running)
        return;
    else {
        _running = true;
        _enabled = true;
        _thread = std::thread(&Thread::run, this);
    }
}

void Thread::run() {
    while(_running) {
        if(_enabled)
            loop();
        msleep(20);
    }
}

void Thread::stop() {
    if(_running)
        _running = false;
}

void Thread::wait() {
    if(_thread.joinable())
        _thread.join();
}

void Thread::msleep(unsigned long ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
