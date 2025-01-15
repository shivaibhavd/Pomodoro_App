#include "../include/app.h"
#include <iostream>

int main()
{
    try
    {
        App app;
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cout << "An error occurred: " << e.what() << std::endl;
        return 1; // indicates failure
    }

    return 0;
}