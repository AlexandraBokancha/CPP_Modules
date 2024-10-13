#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
//# include <typeinfo>

enum TypeName{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    WRONG
};

class ScalarConverter
{
    public:

        /* pure virtual destructor to prevent an instantinatoin */
        virtual ~ScalarConverter() = 0;
        
        /* static method */
        static  void convert(const std::string & str);
};

#endif

