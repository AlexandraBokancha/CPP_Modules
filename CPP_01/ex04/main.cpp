#include "Sed.hpp"

int main(int ac, char **av)
{
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (ac != 4)
    {
        std::cerr << "Wrong number of arguments" << std::endl;
        return (-1);
    }
    if (s1.empty() || s2.empty())
    {
        std::cerr << "Provided strings cannot be empty" << std::endl;
        return (-1);
    }
    Sed sed(av[1]);
    if (sed.replace(s1, s2))
        return (-1);    
    return (0);
};
