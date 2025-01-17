#include "../include/app.h"
#include "../include/notifier.h"
#include "../include/exceptions.h"
#include <iostream>

int main()
{
    auto notifier = std::make_unique<ConsoleNotifier>();
    App app(std::move(notifier));
    if (!app.run())
    {
        std::cout << "An error occurred during execution." << std::endl; //Feedback_17Jan why not notify the user?
        return 1; // indicates failure
    }
    
    return 0;
}