#pragma once
#include <chrono>

class Timer
{
public:
    enum class State
    {
        STOPPED,
        WORK,
        BREAK,
        PAUSED
    };

    // Constructor
    Timer();

    // Timer methods
    bool start(int workDurationInSeconds, int breakDurationInSeconds);
    bool pause(); 
    bool resume();
    bool stop();  
    bool reset(); 

    // Check timer state
    bool isWorkTime() const;
    bool isBreakTime() const;
    bool isPaused() const;
    bool isStopped() const;
    bool isRunning() const;

    // Timer transition
    void transition();

    // Increment cycle count
    void incrementCycleCount();

    // Getters
    int getRemainingTime() const;
    int getWorkDuration() const;
    int getBreakDuration() const;
    int getCycleCount() const;
    State getState() const;

    // Default durations in seconds
    static const int defaultWorkDurationInSeconds = 25 * 60; 
    static const int defaultBreakDurationInSeconds = 5 * 60;

private:
    State timerState;
    int workDuration = 0;
    int breakDuration = 0;
    int cycleCount = 0;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point pauseTime;

public:
};