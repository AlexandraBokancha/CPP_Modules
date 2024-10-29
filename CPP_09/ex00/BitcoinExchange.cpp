#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange(void): _fileName("input.txt")
{
  //  std::cout << "Default constructor called" << std::endl;
    loadInputFile(_fileName);
    return ;
}
// Default constructor
BitcoinExchange::BitcoinExchange(const char *fileName): _fileName(fileName)
{
   // std::cout << "Parametric constructor called" << std::endl;
    loadInputFile(_fileName);
    return ;
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
   // std::cout << "Destructor called" << std::endl;
    return ;
}
void BitcoinExchange::displayFileContent() {
    for (std::map<std::string, std::vector<float> >::iterator it = _fileContent.begin(); it != _fileContent.end(); ++it) {
        std::cout << "Date: " << it->first << " | Values: ";
        for (std::vector<float>::iterator valueIt = it->second.begin(); valueIt != it->second.end(); ++valueIt) {
            std::cout << *valueIt << std::endl;
        }
    }
}


bool BitcoinExchange::isValidDate(std::string & date){
  if (date.size() != 11 || date[4] != '-' || date[7] != '-'){
        std::cout << "Wrong date format => " << date.size() << std::endl;
        return false;
    }
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
   
    unsigned short tmpYear, tmpMonth, tmpDay;
   
    std::istringstream(year) >> tmpYear;
    std::istringstream(month) >> tmpMonth;
    std::istringstream(day) >> tmpDay;

    if (tmpMonth > 12 || !tmpYear || !tmpMonth || !tmpDay){
        std::cout << "Wrong date format => " << date << std::endl;
        return false;
    }
    unsigned short monthlen[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if ((!(tmpYear%4) && (tmpYear%100)) || !(tmpYear%400)) // check if year is a leap year
        monthlen[1]++;
    if (tmpDay > monthlen[tmpMonth - 1]){
        std::cout << "Wrong day format => " << date << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(std::string & valueStr){
    float value;
    value = static_cast<float>(std::atof(valueStr.c_str()));
    if (value < 0){
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    else if (value > 1000){
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::convert(std::map<std::string, std::vector<float> > fileContent){
    (void)fileContent;
    displayFileContent();
}

void BitcoinExchange::loadInputFile(const char * fileName){
    std::ifstream inputFile;
    inputFile.open(fileName);
    if (!inputFile)
        std::cerr << "Error: could not open file" << std::endl;
    std::string line;
    while (std::getline(inputFile, line)){
        std::istringstream ss(line);
        std::string key, valueStr;
        if (line == "date | value")
            continue;
        if (std::getline(ss, key, '|') && std::getline(ss, valueStr)){
            if (!isValidDate(key))
                continue;
            if (isValidValue(valueStr)){
                float value = static_cast<float>(std::atof(valueStr.c_str()));
                _fileContent[key].push_back(value);
            }
        }
        else
           std::cerr << "Error: bad input => " << line << std::endl;
    }
    inputFile.close();
    convert(_fileContent);
}
