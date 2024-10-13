#include "PhoneBook.hpp"

int main()
{
    PhoneBook MyBook;

    std::cout << "Hi ! This is your phonebook. \n";
    std::cout << "You can use only 3 commands: \n";
    std::cout << "ADD, SEARCH and EXIT.\n" << std::endl;
    while (1)
    {
        std::cout << "Enter your command: ";
        if (!std::getline(std::cin, MyBook.cmd) || !MyBook.cmd.compare("EXIT") )
            break;
        else if (!MyBook.cmd.compare("ADD"))
            MyBook.add_contact();
        else if (!MyBook.cmd.compare("SEARCH"))
            MyBook.search_contact();
        else
            std::cout << "Wrong command, try again.\n";    
    }
    return (0);
}
