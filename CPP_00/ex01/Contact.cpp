#include "PhoneBook.hpp"

Contact::~Contact(){
    return;
}

std::string  Contact::GetFirstName(){
    return (Contact::_first_name);
}

std::string  Contact::GetLastName(){
    return (Contact::_last_name);
}

std::string  Contact::GetNickName(){
    return (Contact::_nickname);
}

std::string  Contact::GetPhoneNumber(){
    return (Contact::_tel);
}

std::string  Contact::GetSecret(){
    return (Contact::_secret);
}
