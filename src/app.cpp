#include "../include/app.h"
#include "../include/exceptions.h"
#include <iostream>

App::App()
{
    running = true;
    notifier = std::unique_ptr<INotifier>(new ConsoleNotifier()); // feedback_15Jan: broken Dependency Inversion principle
}

void App::displayTime(int timeInSeconds) const
{
    int minutes = timeInSeconds / 60;
    int remainingSeconds = timeInSeconds % 60;
    std::cout << minutes << ":" << (remainingSeconds < 10 ? "0" : "") << remainingSeconds << std::endl;
}

bool App::run() noexcept
{
    try
    {
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
                        char useDefault;
                        std::cout << "Use default durations (25min/5min)? [y/n]: ";
                        std::cin >> useDefault;

                        if (useDefault == 'y' || useDefault == 'Y')
                        {
                            timer.start(Timer::defaultWorkDurationInSeconds, Timer::defaultBreakDurationInSeconds);
                            notifier->notify("Work session started with default duration (25min)");
                        }
                        else if (useDefault == 'n' || useDefault == 'N')
                        {
                            int workDuration, breakDuration;
                            std::cout << "Enter work duration (seconds): ";
                            std::cin >> workDuration;
                            std::cout << "Enter break duration (seconds): ";
                            std::cin >> breakDuration;
                            timer.start(workDuration, breakDuration);
                            notifier->notify("Work session started");
                        }
                        else
                        {
                            notifier->notify("Invalid option! Please try again");
                        }
                    }
                    else
                    {
                        notifier->notify("Timer is already running");
                    }
                    break;
                case '2':
                    if (timer.isWorkTime())
                    {
                        timer.pause();
                        notifier->notify("Work session paused");
                    }
                    else
                    {
                        notifier->notify("Cannot pause. Timer is not in work session");
                    }
                    break;
                case '3':
                    if (timer.isPaused())
                    {
                        timer.resume();
                        notifier->notify("Work session resumed");
                    }
                    else
                    {
                        notifier->notify("Cannot resume. Timer is not paused");
                    }
                    break;
                case '4':
                    timer.reset();
                    notifier->notify("Timer reset");
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
                        notifier->notify("No active session");
                    }
                    break;
                case '6':
                    running = false;
                    notifier->notify("Exiting...");
                    break;
                default:
                    notifier->notify("Invalid option! Please try again");
                }

                Timer::State previousState = timer.getState();
                timer.transition();
                Timer::State currentState = timer.getState();

                if (previousState == Timer::State::WORK && currentState == Timer::State::BREAK)
                {
                    notifier->notify("Work session complete! Time for a break");
                }
                else if (previousState == Timer::State::BREAK && currentState == Timer::State::STOPPED)
                {
                    notifier->notify("Break session complete! Cycle " + std::to_string(timer.getCycleCount()) + " finished!");
                }
            }
            catch (const std::exception &e)
            {
                notifier->notify(std::string("Error: ") + e.what());
            }
        }
        return true; // Indicate success
    }
    catch (const std::exception& e)
    {
        notifier->notify(std::string("Error: ") + e.what());
        return false; // Indicate failure
    }
}