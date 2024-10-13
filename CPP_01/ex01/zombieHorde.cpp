#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    Zombie *pHzombie;
    
    if (N <= 0)
        return (0);
    pHzombie = new Zombie[N];
    for (int i = 0; i < N; i++){
        pHzombie[i].setZombie(name);
    };
    return (pHzombie);
}
