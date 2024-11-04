#include "PmergeMe.hpp"

int main(int ac, char *av[]){
    if (ac > 2){
        try{
            PmergeMe input;
            input.FJMI(ac, av);
        }
        catch (std::exception & e){
            std::cout << e.what() << std::endl;
        }
    }
    else{
        std::cout << "Usage: ./PmergeMe |positive integers array|" << std::endl;
        return 1;
    }
    return 0;
}