#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

enum ScalarTypes{
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

class ScalarConverter
{
        /* to prevent an instanciation wi will put a 
        constructor to private */

    private:
        
        ScalarConverter();
        ScalarConverter(const ScalarConverter & other);
        ~ScalarConverter();
    
    public:
        
        /* static method */

        static  void convert(const std::string & str);
};

#endif

