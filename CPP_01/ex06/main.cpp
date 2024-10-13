#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Harl harlFilter;
        std::string  level = av[1];
        harlFilter.complain(level);
    }
    else
        std::cout << "Wrong number of arguments" << std::endl;
    return (0);
}
