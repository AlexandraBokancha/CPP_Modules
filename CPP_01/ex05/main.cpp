#include "Harl.hpp"

int main()
{
    Harl    harl;
    std::string level;

    std::cout << "Hi! This is Harl. I have 4 levels that you can use" << "\n" \
            << "\n" \
            << "[DEBUG] : Debug messages contain contextual information" << "\n" \
            << "[INFO] : These messages contain extensive information" << "\n" \
            << "[WARNING] : Warning messages indicate a potential issue in the system" << "\n" \
            << "[ERROR] : These messages indicate an unrecoverable error has occurred." << "\n" \
            << std::endl;

    while (1)
    {
        std::cout << "Enter your choice" << std::endl;
        if (!std::getline(std::cin, level) || !level.compare("exit"))
            break;
        harl.complain(level);
    }        
    return (0);
}