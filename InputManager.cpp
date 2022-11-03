#include "InputManager.h"

InputManager::InputManager()
{

}

void InputManager::TakeInput(std::string &from, std::string &to)
{
    while (true)
    {
        std::string x = "1";
        /*
        std::cout << "Wybierz opcje:" << std::endl;
        std::cout << "1. Daj ruch" << std::endl;
        std::cout << "2. Poddaj gre" << std::endl;
        std::cout << "3. Cofnij ruch" << std::endl;
        std::cin >> x;*/


        if (x == "1")
        {
            std::cout << "Podaj pole skad: ";
            std::cin >> from;
            std::cout << std::endl;
            std::cout << "Podaj pole dokad: ";
            std::cin >> to;
            std::cout << std::endl;
            return;
        }
        else if (x == "2")
        {
            from = "resign";
            return;
        }
        else if (x == "3")
        {
            from = "back";
            return;
        }
        std::cout << "Bledny wybor" << std::endl;
    }

}