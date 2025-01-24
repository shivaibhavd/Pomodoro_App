#include "app.h"
#include "notifier.h"
#include "exceptions.h"
#include <iostream>

int main()
{
    auto notifier = std::make_unique<ConsoleNotifier>();
    App app(std::move(notifier));
    if (!app.run())
    {
        notifier->notify("An error occurred during execution.");
        return 1; // indicates failure
    }
    
    return 0;
}