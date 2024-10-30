#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <iterator>
# include <sstream>
# include <algorithm>

/* 
1. upload data.csv to a map
2. open an input file
3. parse to check the format
4. check the value from input file in data.csv
5. display result
*/

class BitcoinExchange
{
    private: 

        std::string _fileName;
        std::multimap<std::string, float> _data;
        void    initialize(const std::string & fileName);

    public:

        BitcoinExchange(void);
        explicit BitcoinExchange(const std::string & fileName);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void    loadDataBase();
        void    loadInputFile(const std::string & fileName);
        bool    isValidDate(const std::string & date) const;
        bool    isValidValue(const std::string & value) const;
        float   getRateFromData(const std::string & date) const;
};

#endif

