#include "RPN.hpp"

int main(int ac, char *av[]){
    if (ac == 2){
        try{
            RPN exp;
            std::string str = av[1];
            exp.evaluateExpression(str);
        }
        catch (std::exception & e){
            std::cout << e.what() << std::endl;
        }
    }
    else{
        std::cout << "Usage: ./RPN |expression|" << std::endl;
        return 1;
    }
    return 0;
}