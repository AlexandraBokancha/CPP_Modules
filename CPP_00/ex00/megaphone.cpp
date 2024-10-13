#include <iostream>
#include <cctype> // functions to classify and transform char;
#include <cstring> // functions to manipulate strings and arrays;

int main(int ac, char **av)
{
    if (ac > 1)
    {
        for (int i = 1; i < ac; ++i)
        {
            for (int j = 0; j < (int)std::strlen(av[i]); ++j)
                av[i][j] = (char)std::toupper(av[i][j]);
            std::cout << av[i];
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}
