#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <iterator>
# include <vector>
# include <sstream>
# include <stdlib.h>

/* 
1. open an input file
2. parse to check the format
3. upload data.csv to a map
4. check the value from input file in data.csv
5. display result
*/

class BitcoinExchange
{
    private: 
        const char * _fileName;
        std::map<std::string, float> _data;
        std::map<std::string, float > _fileContent;

    public:
        BitcoinExchange(void);
        BitcoinExchange(const char * fileName);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadInputFile(const char * fileName);
        void displayFileContent();
        bool isValidDate(std::string & date);
        bool isValidValue(std::string & value);
        void convert(std::map<std::string, std::vector<float> > fileContent);
};

#endif

