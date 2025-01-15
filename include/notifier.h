#pragma once
#include <string>

// Abstract base class for notifications
class INotifier        
{
public:
    virtual ~INotifier() = default;
    virtual void notify(const std::string &message) = 0;
};

// Concrete implementation for console notifications
class ConsoleNotifier : public INotifier
{
public:
    void notify(const std::string &message) override; // override to ensure this method overrides a base class method
};