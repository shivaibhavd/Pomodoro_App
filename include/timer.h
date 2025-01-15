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

    // Default durations in seconds
    static const int defaultWorkDuration = 25 * 60;
    static const int defaultBreakDuration = 5 * 60;

private:
    State timerState;
    int workDuration;
    int breakDuration;
    int cycleCount;
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

    // Increment cycle count
    void incrementCycleCount();

    // Getters
    int getRemainingTime() const;
    int getWorkDuration() const;
    int getBreakDuration() const;
    int getCycleCount() const;
    State getState() const;
};