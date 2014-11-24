/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#include "thread.h"

Thread::Thread() {
    _isRunning = false;
}

void Thread::start() {
    if(_isRunning)
        return;
    else {
        _isRunning = true;
        _thread = std::thread(&Thread::runThread, this);
    }
}

void Thread::wait() {
    if(isRunning() && _thread.joinable())
        _thread.join();
}

void Thread::runThread() {
    run();
    _isRunning = false;
}

void Thread::msleep(unsigned long ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
