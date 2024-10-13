#include "Zombie.hpp"

int main(void)
{
    std::string name;
    int N;

    std::cout << "Zombie's name: " << std::endl;
    std::cin >> name;
    std::cout << "Number of zombies: " << std::endl;
    std::cin >> N;
    
    Zombie *phZombie = zombieHorde(N, name);
    
    /* To check if all zombies were created */
    for (int i = 0; i < N; i++)
        phZombie[i].announce();
   
    delete[] phZombie;
    return (0);
};