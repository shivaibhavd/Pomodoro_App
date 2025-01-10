#pragma once
#include <string>
#include <chrono>

class Timer
{
private:
    std::string timerState; // "running", "paused", "stopped"
    int timerDuration;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point pauseTime;
    int pausedDuration;

public:
    // Constructor
    Timer();

    // Timer methods
    void start(int timeDuration);
    void pause();
    void resume();
    void stop();
    void reset();

    // Check timer state
    bool isRunning();
    bool isPaused();
    bool isStopped();

    // Getters
    int getRemainingTime();
    int getDuration();
    std::string getState();
};