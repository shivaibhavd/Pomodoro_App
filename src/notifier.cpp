#include "../include/notifier.h"
#include <iostream>

void ConsoleNotifier::notify(const std::string &message)
{
    std::cout << "\n=== " << message << " ===\n" << std::endl;
}