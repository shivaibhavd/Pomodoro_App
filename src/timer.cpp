#include "../include/timer.h"
#include <stdexcept>

Timer::Timer()
{
    timerState = "stopped";
    timerDuration = 0;
    pausedDuration = 0;
}

void Timer::start(int timerDuration)
{
    if (timerDuration <= 0)
    {
        throw std::invalid_argument("Timer duration must be greater than 0");
    }

    this->timerDuration = timerDuration;
    timerState = "running";
    startTime = std::chrono::steady_clock::now();
    pausedDuration = 0;
}

void Timer::pause()
{
    if (timerState != "running")
    {
        throw std::runtime_error("Timer must be running to pause");
    }

    timerState = "paused";
    pauseTime = std::chrono::steady_clock::now();
}

void Timer::resume()
{
    if (timerState != "paused")
    {
        throw std::runtime_error("Timer must be paused to resume");
    }

    auto pauseDuration = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - pauseTime).count();
    pausedDuration += pauseDuration;
    timerState = "running";
}