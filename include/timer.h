#pragma once
#include <chrono>

class Timer
{
public: // feedback_15Jan: Ideally, just have all public members in one place, not two public sections
    enum class State
    {
        STOPPED,
        WORK,
        BREAK,
        PAUSED
    };

    // Default durations in seconds
    static const int defaultWorkDuration = 25 * 60; // feedback_15Jan: Always have units in var names, eg. defaultWorkDurInSecs
    static const int defaultBreakDuration = 5 * 60; // feedback_15Jan: Always have units in var names, eg. defaultWorkDurInSecs

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
    void start(int workDuration, int breakDuration); // feedback_15Jan: consider alternate return val that tells if it failed or succeeded
    void pause(); // feedback_15Jan: consider alternate return val that tells if it failed or succeeded
    void resume(); // feedback_15Jan: consider alternate return val that tells if it failed or succeeded
    void stop(); // feedback_15Jan: consider alternate return val that tells if it failed or succeeded
    void reset(); // feedback_15Jan: consider alternate return val that tells if it failed or succeeded

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