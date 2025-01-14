#include <iostream>
#include <chrono>
#include "../include/timer.h"

void displayTime(int seconds)
{
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;
    std::cout << minutes << ":"
              << (remainingSeconds < 10 ? "0" : "") << remainingSeconds
              << std::endl;
}

int main()
{
    Timer timer;
    bool running = true;

    while (running)
    {
        std::cout << "\nPomodoro Timer\n";
        std::cout << "1. Start Work Session\n";
        std::cout << "2. Pause Work Session\n";
        std::cout << "3. Resume Work Session\n";
        std::cout << "4. Reset Timer\n";
        std::cout << "5. Show Current Time\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";

        char choice;
        std::cin >> choice;

        try
        {
            switch (choice)
            {
            case '1':
                if (!timer.isRunning())
                {
                    int workDuration, breakDuration;
                    std::cout << "Enter work duration (seconds): ";
                    std::cin >> workDuration;
                    std::cout << "Enter break duration (seconds): ";
                    std::cin >> breakDuration;
                    timer.start(workDuration, breakDuration);
                    std::cout << "Work session started.\n";
                }
                else
                {
                    std::cout << "Timer is already running.\n";
                }
                break;
            case '2':
                if (timer.isWorkTime())
                {
                    timer.pause();
                    std::cout << "Work session paused.\n";
                }
                else
                {
                    std::cout << "Cannot pause. Timer is not in work session.\n";
                }
                break;
            case '3':
                if (timer.isPaused())
                {
                    timer.resume();
                    std::cout << "Work session resumed.\n";
                }
                else
                {
                    std::cout << "Cannot resume. Timer is not paused.\n";
                }
                break;
            case '4':
                timer.reset();
                std::cout << "Timer reset.\n";
                break;
            case '5':
                if (timer.isRunning() || timer.isPaused())
                {
                    int remainingTime = timer.getRemainingTime();
                    std::cout << "Current time remaining: ";
                    displayTime(remainingTime);
                }
                else
                {
                    std::cout << "No active session.\n";
                }
                break;
            case '6':
                running = false;
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid option! Please try again.\n";
            }

            // Use the transition function to handle state changes
            Timer::State previousState = timer.getState();
            timer.transition();
            Timer::State currentState = timer.getState();

            // Print messages based on state transitions
            if (previousState == Timer::State::WORK && currentState == Timer::State::BREAK)
            {
                std::cout << "\nWork session complete! Time for a break.\n";
            }
            else if (previousState == Timer::State::BREAK && currentState == Timer::State::STOPPED)
            {
                std::cout << "\nBreak session complete! Timer will reset.\n";
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}