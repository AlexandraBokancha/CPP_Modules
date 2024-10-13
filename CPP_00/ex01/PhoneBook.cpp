#include "PhoneBook.hpp"

PhoneBook::~PhoneBook(){
    return ;
}

void    PhoneBook::add_contact()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_num;
    std::string secret;
    
    std::cout << "First name: ";
    std::getline(std::cin, first_name);
    std::cout << "Last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone number: ";
    std::getline(std::cin, phone_num);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, secret);
    SetContactFirstName(first_name, index);
    SetContactLastName(last_name, index);
    SetContactNickName(nickname, index);
    SetContactPhoneNum(phone_num, index);
    SetContactSecret(secret, index);
    if (PhoneBook::_contacts[index].GetSecret().empty() || PhoneBook::_contacts[index].GetPhoneNumber().empty() || \
        PhoneBook::_contacts[index].GetFirstName().empty() || PhoneBook::_contacts[index].GetLastName().empty() || \
        PhoneBook::_contacts[index].GetNickName().empty())
    {
        std::cout << "\033[1;32mSorry, there is en emplty field. Please, try again.\033[0m\n";
        PhoneBook::add_contact();
        return ;
    }
    std::cout << "\033[1;33mYour contact is saved to this phonebook!\033[0m\n";
    PhoneBook::index++;
    if (PhoneBook::index == 8)
        PhoneBook::index = 0;
    return ;
}

void    PhoneBook::display_contacts()
{
    int i = 0;

    std::cout << '\n' << std::right << std::setw(10) << "Index" << "|" \
        << std::right << std::setw(10) << "First name" << "|" \
        << std::right << std::setw(10) << "Last name" << "|" \
        << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
    if (PhoneBook::_contacts[0].GetFirstName().empty())
        return ;
    while (i != 8)
    {
        std::string first_name = PhoneBook::_contacts[i].GetFirstName();
        std::string last_name = PhoneBook::_contacts[i].GetLastName();
        std::string nickname = PhoneBook::_contacts[i].GetNickName();  
        if (first_name.empty())
            break ;
        std::cout << std::right << std::setw(10) << i + 1 << "|";
        if (first_name.size() > 10)
            first_name.replace(9, \
                first_name.size() - 9, ".");
        std::cout << std::right << std::setw(10) << first_name << "|"; 
        if (last_name.size() > 10)
            last_name.replace(9, \
                last_name.size() - 9, ".");
        std::cout << std::right << std::setw(10) << last_name << "|"; 
        if (nickname.size() > 10)
            nickname.replace(9,
                nickname.size() - 9, ".");
        std::cout << std::right << std::setw(10) << nickname << "|" \
            << std::endl;
        i++;
    }
    std::cout << '\n';
}

void    PhoneBook::search_contact()
{
    std::string tmp;
    int i;

    /* 1. Display a table of contacts:
            - there is 4 columns;
            - each column must be 10 char wide;
            - a ('|') separates them;
            - if the text is longer than 10 char wide, it must be truncated with ('.');
    */
    
    PhoneBook::display_contacts();
    
    /* 2. Ask the user for the entry to display */ 

    std::cout << "Enter an index from 1 to 8: " << std::endl;
    std::getline(std::cin, tmp);
    i = atoi(tmp.c_str());
    if (i > 0 && i < 9 && !PhoneBook::_contacts[i - 1].GetFirstName().empty())
    {
        i--;
        std::cout << "Here some more details about this contact: \n";
        std::cout << '\n';
        std::cout << "First name: " << PhoneBook::_contacts[i].GetFirstName() << std::endl;
        std::cout << "Last name: " << PhoneBook::_contacts[i].GetLastName() << std::endl;
        std::cout << "Nickname: " << PhoneBook::_contacts[i].GetNickName() << std::endl;
        std::cout << "Phone number: " << PhoneBook::_contacts[i].GetPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << PhoneBook::_contacts[i].GetSecret() << std::endl;
        std::cout << '\n';
    }
    else
        std::cout << "Wrong index, this contact doesn't exist.\n";
    return ;
}

