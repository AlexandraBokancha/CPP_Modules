#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"


class Harl{

    private:

        void    _debug( void );
        void    _info( void );
        void    _warning( void );
        void    _error( void );

    public:

        Harl();
        ~Harl();

        void    complain( std::string level );
};

#endif