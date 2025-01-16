#include "../include/timer.h"
#include <stdexcept>
#include <chrono>

Timer::Timer()
{
    timerState = State::STOPPED;
    workDuration = Timer::workDuration;
    breakDuration = Timer::breakDuration;
    cycleCount = Timer::cycleCount;
}

bool Timer::start(int workDurationInSeconds, int breakDurationInSeconds)
{
    if (workDurationInSeconds <= 0 || breakDurationInSeconds <= 0)
    {
        return false;
        throw std::invalid_argument("Durations must be greater than 0"); // feedback_15Jan: 1. Use custom exception for the app level functionality failure, here for eg. APP_INVALID_TIMER_PARAMS & you can then handle those separetly the App level by adjusting to default values and notifying the user
    }
    
    workDuration = workDurationInSeconds;
    breakDuration = breakDurationInSeconds;
    timerState = State::WORK;
    startTime = std::chrono::steady_clock::now();
    return true;
}

bool Timer::pause() 
{
    if (timerState == State::PAUSED || timerState == State::STOPPED)
    {
        return false;
    }
    if (timerState == State::BREAK)
    {
        return false;
        throw std::runtime_error("Cannot pause during break");
    }

    timerState = State::PAUSED;
    pauseTime = std::chrono::steady_clock::now();
    return true;
}

bool Timer::resume()
{
    if (timerState == State::WORK || timerState == State::BREAK)
    {
        return false;
    }
    if (timerState == State::STOPPED)
    {
        return false;
        throw std::runtime_error("Cannot resume while stopped");
    }

    auto pauseDuration = std::chrono::steady_clock::now() - pauseTime;
    startTime += pauseDuration; // Adjust start time to account for pause
    timerState = State::WORK;
    return true;
}

bool Timer::stop()
{
    if (timerState == State::STOPPED)
    {
        return false;
    }

    timerState = State::STOPPED;
    return true;
}

bool Timer::reset()
{
    if (timerState == State::STOPPED)
    {
        return false;
    }

    timerState = State::STOPPED;
    workDuration = 0;
    breakDuration = 0;
    cycleCount = 0;
    return true;
}

bool Timer::isWorkTime() const
{
    return timerState == State::WORK;
}

bool Timer::isBreakTime() const
{
    return timerState == State::BREAK;
}

bool Timer::isPaused() const
{
    return timerState == State::PAUSED;
}

bool Timer::isStopped() const
{
    return timerState == State::STOPPED;
}

int Timer::getRemainingTime() const
{
    if (timerState == State::STOPPED)
    {
        return 0;
    }

    auto now = (timerState == State::PAUSED) ? pauseTime : std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
    int remainingTime = 0;

    if (timerState == State::WORK || timerState == State::PAUSED)
    {
        remainingTime = workDuration - static_cast<int>(elapsedTime);
    }
    else if (timerState == State::BREAK)
    {
        remainingTime = breakDuration - static_cast<int>(elapsedTime);
    }

    return remainingTime;
}

int Timer::getWorkDuration() const
{
    return workDuration;
}

int Timer::getBreakDuration() const
{
    return breakDuration;
}

Timer::State Timer::getState() const
{
    return timerState;
}

bool Timer::isRunning() const
{
    return timerState == State::WORK || timerState == State::BREAK;
}

void Timer::incrementCycleCount()
{
    cycleCount++;
}

int Timer::getCycleCount() const
{
    return cycleCount;
}

void Timer::transition()
{
    if (isWorkTime() && getRemainingTime() <= 0)
    {
        timerState = State::BREAK;
        startTime = std::chrono::steady_clock::now();
    }
    else if (isBreakTime() && getRemainingTime() <= 0)
    {
        incrementCycleCount();
        timerState = State::STOPPED;
    }
}
