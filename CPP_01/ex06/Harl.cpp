#include "Harl.hpp"

Harl::Harl(){
    std::cout << "Harl is ready" << std::endl;
}

void    Harl::_debug( void ){
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << GREEN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger";
    std::cout << GREEN << " I really do!" << RESET << std::endl;
    std::cout << std::endl;
}

void    Harl::_info( void ){
    std::cout << "[ INFO ]" << std::endl;
    std::cout << GREEN << "I cannot believe adding extra bacon costs more money.";
    std::cout << GREEN << " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
    std::cout <<  RESET << std::endl;
    std::cout << std::endl;
}

void    Harl::_warning( void ){
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << GREEN << "I think I deserve to have some extra bacon for free.";
    std::cout << GREEN << " I’ve been coming for years whereas you started working here since last month.";
    std::cout << RESET << std::endl;
    std::cout << std::endl;
}

void    Harl::_error( void ){
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << GREEN << "This is unacceptable! I want to speak to the manager now." <<  RESET << std::endl;
    std::cout << std::endl;
}

void    Harl::complain( std::string level )
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

    while (i < 4 && levels[i].compare(level))
        i++;
    switch (i)
    {
        case 0:
            this->_debug();
        case 1:
            this->_info();
        case 2:
            this->_warning();
        case 3:
            this->_error();
            break;
        default: 
            std::cout << RED << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
    }
}

Harl::~Harl(){
    std::cout << "Harl is finished" << std::endl;
}
