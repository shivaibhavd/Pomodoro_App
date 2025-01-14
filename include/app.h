#pragma once
#include "timer.h"

class App
{
private:
    Timer timer;
    bool running;

    void displayTime(int seconds) const;

public:
    App();
    void run();
};