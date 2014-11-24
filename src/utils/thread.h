/***
 * SCC0604 - Programação Orientada a Objetos
 * Universidade de São Paulo - São Carlos (SP)
 * Esse arquivo é parte do Trabalho 3.
 * Aluno: Guilherme Caixeta de Oliveira (gcaixetaoliveira@gmail.com)
 **/

#ifndef THREAD_H
#define THREAD_H

#include <iostream>
#include <thread>
#include <chrono>

class Thread {
public:
    Thread();

    // Returns if thread is currently running
    bool isRunning() const { return _isRunning; }

    // Starts the thread
    void start();

    // Block until thread finishes
    void wait();

    // Static method for sleeping
    static void msleep(unsigned long ms);
private:
    //
    void runThread();
    virtual void run() = 0;

    bool _isRunning;
    std::thread _thread;
};

#endif // THREAD_H
