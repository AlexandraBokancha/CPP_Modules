#include "BitcoinExchange.hpp"

int main(int ac, char *av[]){
    if (ac == 2)
        BitcoinExchange btc(av[1]);
    else
        std::cout << "Error: could not open file" << std::endl;
}