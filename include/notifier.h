#pragma once
#include <string>

// Abstract base class for notifications
class Notifier
{
public:
    virtual ~Notifier() = default;
    virtual void notify(const std::string &message) = 0;
};

// Concrete implementation for console notifications
class ConsoleNotifier : public Notifier
{
public:
    void notify(const std::string &message) override;
};