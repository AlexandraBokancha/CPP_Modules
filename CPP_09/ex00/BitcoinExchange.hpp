#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <iterator>
# include <sstream>
# include <algorithm>

class BitcoinExchange
{
    public:
        // Constructors, Destructor, Assignment Operator
        BitcoinExchange(void);
        explicit BitcoinExchange(const std::string & fileName);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        // Load data from a file
        void    loadDataBase();
        void    loadInputFile(const std::string & fileName);
        
        // Check if date and value from input file are valid
        bool    isValidDate(const std::string & date) const;
        bool    isValidValue(const std::string & value) const;
        
        // Retrieve the exchange rate for a specific date from the database
        float   getRateFromData(const std::string & date) const;
    
    private: 

        // Name of the input file to load data from
        std::string _fileName;

        // Multimap to store exchange rate data with date as the key
        std::multimap<std::string, float> _data;

        // Helper function to initialize data from the specified file
        void    initialize(const std::string & fileName);
};

#endif

