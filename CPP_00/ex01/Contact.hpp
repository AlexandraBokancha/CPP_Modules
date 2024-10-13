#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "PhoneBook.hpp"

class Contact 
{
    private :
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _tel;
        std::string _secret;

    public :
        /* Constructor  (initialisation list) */
        Contact() : _first_name(""), _last_name(""), _nickname(""), \
        _tel(""), _secret("") {};

        /* Deconstructor */
        ~Contact();

        /* Setters */
        void         SetFirstName(std::string first_name){
            this->_first_name = first_name; // key-word this-> to refer to your current instance
        }
        void         SetLastName(std::string last_name){
            this->_last_name = last_name;
        }
        void         SetNickName(std::string nickname){
            this->_nickname = nickname;
        }
        void         SetPhoneNum(std::string phone_num){
            this->_tel = phone_num;
        }
        void         SetSecret(std::string secret){
            this->_secret = secret;
        }

        /* Getters */
        std::string  GetFirstName();
        std::string  GetLastName();
        std::string  GetNickName();
        std::string  GetPhoneNumber();
        std::string  GetSecret();
};

#endif