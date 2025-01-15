#pragma once
#include "timer.h"
#include "notifier.h"
#include <memory>

class App
{
private:
    Timer timer;
    bool running;
    std::unique_ptr<Notifier> notifier; // feedback_15Jan: why unique_ptr, put a comment
    

    void displayTime(int seconds) const; // feedback_15Jan: good, put the rationale of the const in comment

public:
    App(); 
    void run(); // feedback_15Jan: how would you know if run failed + ideally run should be noexcept 
};