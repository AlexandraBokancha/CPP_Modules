#include "ScalarConverter.hpp"

/*  si tu veux tester avec des overflow :
    char: 127
    int: 2147483647
    float: 3.40282e+38
    double: 1.79769e+308
*/

int main(int ac, char **av){
    if (ac == 2)
        ScalarConverter::convert(av[1]);
    else
        std::cout << "Usage: ./converter |literal|" << std::endl;
    return 0;
}