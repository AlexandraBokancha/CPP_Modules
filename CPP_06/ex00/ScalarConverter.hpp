#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <climits>
# include <cerrno>
# include <cfloat>

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

