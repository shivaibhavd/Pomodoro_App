#include "../include/timer.h"
#include <stdexcept>
#include <chrono>

Timer::Timer()
{
    timerState = State::STOPPED;
    workDuration = 0;
    breakDuration = 0;
    cycleCount = 0;
}

void Timer::start(int workDuration, int breakDuration)
{
    if (workDuration <= 0 || breakDuration <= 0)
    {
        throw std::invalid_argument("Durations must be greater than 0");
    }
    this->workDuration = workDuration;
    this->breakDuration = breakDuration;
    timerState = State::WORK;
    startTime = std::chrono::steady_clock::now();
}

void Timer::pause()
{
    if (timerState != State::WORK)
    {
        throw std::runtime_error("Timer must be in work state to pause");
    }
    timerState = State::PAUSED;
    pauseTime = std::chrono::steady_clock::now();
}

void Timer::resume()
{
    if (timerState != State::PAUSED)
    {
        throw std::runtime_error("Timer must be paused to resume");
    }
    auto pauseDuration = std::chrono::steady_clock::now() - pauseTime;
    startTime += pauseDuration; // Adjust start time to account for pause
    timerState = State::WORK;
}

void Timer::stop()
{
    timerState = State::STOPPED;
}

void Timer::reset()
{
    timerState = State::STOPPED;
    workDuration = 0;
    breakDuration = 0;
    cycleCount = 0;
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

    return remainingTime > 0 ? remainingTime : 0;
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
