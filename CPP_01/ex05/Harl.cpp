#include "Harl.hpp"

Harl::Harl(){
    std::cout << "Harl is ready" << std::endl;
}

void    Harl::_debug( void ){
    std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger";
    std::cout << GREEN << " I really do!" << RESET << std::endl;
}

void    Harl::_info( void ){
    std::cout << GREEN << "I cannot believe adding extra bacon costs more money.";
    std::cout << GREEN << " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
    std::cout <<  RESET << std::endl;
}

void    Harl::_warning( void ){
    std::cout << GREEN << "I think I deserve to have some extra bacon for free.";
    std::cout << GREEN << " I’ve been coming for years whereas you started working here since last month.";
    std::cout << RESET << std::endl;
}

void    Harl::_error( void ){
    std::cout << GREEN << "This is unacceptable! I want to speak to the manager now." <<  RESET << std::endl;
}

void    Harl::complain( std::string level )
{
    LogLevel logLevels [] = {
        {"DEBUG", &Harl::_debug},
        {"INFO",  &Harl::_info},
        {"WARNING", &Harl::_warning},
        {"ERROR", &Harl::_error}
        };

    for (int i = 0; i < 4; i++)
    {
        if (logLevels[i].levelName == level){ 
            (this->*(logLevels[i].pmf))(); // pointer to a member function;
            std::cout << std::endl;
            return ;
        }
    }
    std::cout << RED << "Level not found" << RESET << std::endl;
}

Harl::~Harl(){
    std::cout << "Harl is finished" << std::endl;
}
