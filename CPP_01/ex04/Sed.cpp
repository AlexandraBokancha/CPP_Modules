#include "Sed.hpp"

Sed::Sed( std::string filename ){
    this->_inFile = filename;
    std::cout << filename << " received " << std::endl;
    this->_outFile = this->_inFile + ".replace";
    std::cout << "oufile name is: " << this->_outFile << std::endl;
}

// npos = until the end of the string
// peek = lire le prochain caractere sans deplacer le curseur

int    Sed::replace( const std::string& searchWord, const std::string& replaceWord )
{
    std::ifstream   ifs(_inFile.c_str());
    std::ofstream   ofs(_outFile.c_str());
    std::string     line;
    std::size_t     pos;

    if (ifs.is_open() && ofs.is_open()){
        if (ifs.peek() == EOF){
            std::cout << "File is empty" << std::endl;
            ifs.close();
            ofs.close();
            return (1);
        }
        while (std::getline(ifs, line)){
            pos = line.find(searchWord);
            while (pos != std::string::npos){
                line.erase(pos, searchWord.length());
                line.insert(pos, replaceWord);
                pos = line.find(searchWord, pos + replaceWord.length());
            }
            ofs << line << std::endl;
        }
        ifs.close();
        ofs.close();
    }
    else{
        std::cerr << "error: cannot read a file "  << "[" << _inFile << "]" << std::endl;
        return (1);
    }
    return (0);
}

Sed::~Sed( void ){
    std::cout << "deconstructor called" << std::endl;
    return ; 
}
