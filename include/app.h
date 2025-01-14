#pragma once
#include "timer.h"
#include "notifier.h"
#include <memory>

class App
{
private:
    Timer timer;
    bool running;
    std::unique_ptr<Notifier> notifier;

    void displayTime(int seconds) const;

public:
    App();
    void run();
};