#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <limits>
# include <climits>
# include <cerrno>
# include <cfloat>
# include <cmath>

class ScalarConverter
{
        /* to prevent an instanciation we will put a 
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

