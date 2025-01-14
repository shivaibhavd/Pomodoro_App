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

private:
    State timerState;
    int workDuration;
    int breakDuration;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point pauseTime;

public:
    // Constructor
    Timer();

    // Timer methods
    void start(int workDuration, int breakDuration);
    void pause();
    void resume();
    void stop();
    void reset();

    // Check timer state
    bool isWorkTime() const;
    bool isBreakTime() const;
    bool isPaused() const;
    bool isStopped() const;
    bool isRunning() const;

    // Timer transition
    void transition();

    // Getters
    int getRemainingTime() const;
    int getWorkDuration() const;
    int getBreakDuration() const;
    State getState() const;
};