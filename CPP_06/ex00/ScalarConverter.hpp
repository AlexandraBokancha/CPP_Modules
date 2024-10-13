#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

class ScalarConverter
{
    private:
        
        ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ~ScalarConverter();
    
    public:
        
        /* static method */

        static  void convert(const std::string & str);
};

#endif

