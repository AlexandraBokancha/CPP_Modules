#ifndef SED_HPP
#define SED_HPP
#include <iostream>
#include <fstream>
#include <string>

class   Sed{

    private:

        std::string  _inFile;
        std::string  _outFile;

    public:

        Sed( std::string filename );
        ~Sed();

        int    replace( const std::string& s1, const std::string& s2 );
};

#endif