#include "../include/app.h"
#include "../include/exceptions.h"
#include <iostream>

int main()
{
    App app;
    if (!app.run())
    {
        std::cout << "An error occurred during execution." << std::endl;
        return 1; // indicates failure
    }
    
    return 0;
}