#pragma once
#include "timer.h"
#include "notifier.h"
#include <memory>

class App
{
private:
    Timer &timer; // Reference to the Singleton Timer instance
    bool running;
    std::unique_ptr<INotifier> notifier; // unique_ptr to ensure single ownership and automatic cleanup
    

    void displayTime(int seconds) const; // const as it does not modify any member variables of the class

    void handleStart();
    void handlePause();
    void handleResume();
    void handleReset();
    void handleShowTime();
    void handleExit();

public:
    App(std::unique_ptr<INotifier> notifier); // Constructor with dependency injection
    bool run() noexcept; // noexcept as it should not throw exceptions
};