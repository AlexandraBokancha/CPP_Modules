#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include <cstring> 
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8];

    public :
        std::string cmd;
        int         index;

    /* Constructor */
    PhoneBook() : cmd(""), index(0) {
            for (int i = 0; i < 8; ++i) {
            _contacts[i] = Contact(); // Initialisation of each contact of an array[8]
        }
    };

    /* Deconstructor */
    ~PhoneBook() ;  

    /* Main functions of PhoneBook*/
    void    add_contact();
    void    search_contact();
    void    display_contacts(void);

    /* PhoneBook setters */
    void    SetContactFirstName(std::string first_name, int index){
        _contacts[index].SetFirstName(first_name);
    }
    void    SetContactLastName(std::string last_name, int index){
        _contacts[index].SetLastName(last_name);
    }
    void    SetContactNickName(std::string nickname, int index){
        _contacts[index].SetNickName(nickname);
    }
    void    SetContactPhoneNum(std::string phone_num, int index){
        _contacts[index].SetPhoneNum(phone_num);
    }
    void    SetContactSecret(std::string secret, int index){
        _contacts[index].SetSecret(secret);
    }
};

#endif