#include "ScalarConverter.hpp"

bool isPseudoLiteral(const std::string & str){
    
    /* NaN : not a number (sqrt(-1))*/
    
    if (str == "nan" || str == "nanf"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return true;
    }

    /* inf : infinity (1.0 / 0.0)*/

    if (str == "+inf" || str == "+inff"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return true;
    }
    if (str == "-inf" || str == "-inff"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return true;
    }
    return false;
}

/* strtod: convert strinf to double
Parses the C-string str interpreting its content
as a floating point number and returns its value
as a double.*/
bool isFloatingPoint(const std::string & str){
    char* endptr;
    double nb = std::strtod(str.c_str(), &endptr);
    
    // float
    
    if (*endptr == 'f' && *(endptr + 1) == '\0'){

        if (errno == ERANGE && (nb == HUGE_VAL || nb == -HUGE_VAL) && \
            (nb > std::numeric_limits<float>::max() || nb < std::numeric_limits<float>::min()))
            return false;
        if (nb < CHAR_MIN || nb > CHAR_MAX)
            std::cout << "char: impossible" << std::endl; 
        else if (!std::isprint(static_cast<char>(nb)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
        if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(nb) << std::endl;
        if (nb > std::numeric_limits<float>::max() || nb < -std::numeric_limits<float>::max())
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) \
            << "f" << std::endl;
        std::cout << "double: " << nb << std::endl;
        return true;
    }

    // double
    
    if (*endptr == '\0'){
        if (errno == ERANGE && (nb == HUGE_VAL || nb == -HUGE_VAL) && \
            (nb > std::numeric_limits<double>::max() || nb < std::numeric_limits<double>::min()))
                return false;
        if (nb < CHAR_MIN || nb > CHAR_MAX)
            std::cout << "char: impossible" << std::endl; 
        else if (!std::isprint(static_cast<char>(nb)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
        if (nb > std::numeric_limits<int>::max() || nb < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(nb) << std::endl;
        if (nb > std::numeric_limits<float>::max() || nb < -std::numeric_limits<float>::max())
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) \
            << "f" << std::endl;
        std::cout << "double: " << nb << std::endl;
        return true;
    }
    return false;
}


/* strtol : convert string to long int, 
if endptr is not a null pointer, the function also sets 
the value of endptr to point to the first character after 
the number */
bool isInt(const std::string & str){
    char* endptr;
    long nb = std::strtol(str.c_str(), &endptr, 10);
    if (*endptr == '\0'){
        if (errno == ERANGE && (nb == LONG_MAX || nb == LONG_MIN))
            return false;
        if (nb < CHAR_MIN || nb > CHAR_MAX)
            std::cout << "char: impossible" << std::endl; 
        else if (!std::isprint(static_cast<char>(nb)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
        if (nb > INT_MAX || nb < INT_MIN)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(nb) << std::endl;
        std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(nb) << ".0"<< std::endl;
        return true;
    }
    return false;
}

bool isChar(const std::string & str){
     if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])){
        std::cout << "char: '" << static_cast<char>(str[0]) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[0]) \
            << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
        return true;
    }
    return false;
}

/**
 * @brief Static member function that makes next 4 actions:
 * 1. detect a type of the literal passed as parameter
 * 2. convert it from string to it's actual type
 * 3. convert it EXPLICITLY to three other data types 
 * 4. display results
 */
void ScalarConverter::convert(const std::string & str){
    if (str.empty()){
        std::cout << "The input is empty" << std::endl;
        return ;
    }
    if (!isPseudoLiteral(str) && !isChar(str) \
        && !isInt(str) && !isFloatingPoint(str))
        std::cout << "Invalid input literal" << std::endl;
}
