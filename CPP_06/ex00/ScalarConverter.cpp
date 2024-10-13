#include "ScalarConverter.hpp"


TypeName getType(const std::string & str){
    //std::cout << typeid(str).name() << std::endl;
    return (WRONG);
}

/**
 * @brief Static member function that makes next 4 actions:
 * detect a type
 * convert it from string to it's actual type
 * convert to three other data types 
 * display results
 */
void ScalarConverter::convert(const std::string & str){
   // if empty, display error
   
   TypeName typeInput = getType(str);
   std::cout << typeInput << std::endl;

}

