#include "BitcoinExchange.hpp"

int main(int ac, char *av[]){
    try{
        if (ac == 2){
            std::string str = av[1];
            BitcoinExchange btc(str);
        }
        else
            std::cout << "Usage: ./bts |input file|" << std::endl;
    }
    catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }
}