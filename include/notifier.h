#pragma once
#include <string>

// Abstract base class for notifications
class Notifier              // feedback_15Jan: good idea to mark pure virtual classes (which are technically, interfaces) to use I prefix: INotifier
{
public:
    virtual ~Notifier() = default;
    virtual void notify(const std::string &message) = 0;
};

// Concrete implementation for console notifications
class ConsoleNotifier : public Notifier
{
public:
    void notify(const std::string &message) override; // feedback_15Jan: good practice to use override keyword, const, write rationale as comment
};