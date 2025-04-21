#include "IOHandle.h"

int GetInt(string message)
{
    int number;
    while (true) 
    {
        std::cout << message;
        if (std::cin >> number) 
        {
            break;
        }
        else 
        {
            while (getchar());
        }
    }
    return number;
}

double GetDouble(string message)
{
    double number;
    while (true)
    {
        std::cout << message;
        if (std::cin >> number)
        {
            break;
        }
        else
        {
            while (getchar());
        }
    }
    return number;
}
