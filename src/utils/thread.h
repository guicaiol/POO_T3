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
    virtual ~Thread();

    // Get thread state
    bool isRunning() const { return _running; }
    bool isEnabled() const { return _enabled; }

    // Set thread state
    void enable() { _enabled = true;  }
    void disable() { _enabled = false; }

    // Start/end thread
    void start();
    void stop();

    // Block until thread finishes
    void wait();

    // Static method for sleeping
    static void msleep(unsigned long ms);
private:
    void run();
    virtual void loop() = 0;

    bool _running;
    bool _enabled;
    std::thread _thread;
};

#endif // THREAD_H
