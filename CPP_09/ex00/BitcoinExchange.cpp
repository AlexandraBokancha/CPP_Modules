#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange(void){
  //  std::cout << "Default constructor called" << std::endl;
    initialize("input.txt");
}

// Parametric constructor
BitcoinExchange::BitcoinExchange(const std::string & fileName){
   // std::cout << "Parametric constructor called" << std::endl;
    initialize(fileName);
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _fileName(other._fileName), _data(other._data){
    std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
    std::cout << "Assignment operator called" << std::endl;
    if (this != &other){
        this->_fileName = other._fileName;
        this->_data = other._data;
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange(void){
   // std::cout << "Destructor called" << std::endl;
}

/* 
1. upload data.csv to a map
2. open an input file
3. parse to check the format
4. check the value from input file in data.csv
5. display result
*/

void BitcoinExchange::initialize(const std::string & fileName){
    _fileName = fileName;
    loadDataBase();
    loadInputFile(_fileName);
}

void BitcoinExchange::loadDataBase(){
    std::ifstream   db_file;
    std::string     line;
    db_file.open("data.csv");
    if (!db_file){
        throw std::runtime_error("Error: could not open file");
    }
    std::getline(db_file, line);
    while (std::getline(db_file, line)){
        std::istringstream ss(line);
        std::string date;
        float rate;
        if (std::getline(ss, date, ',') && ss >> rate){
            _data.insert(std::make_pair(date, rate));
        }
    }
    db_file.close();
}

bool BitcoinExchange::isValidDate(const std::string & date) const{
    if (date.size() != 11 || date[4] != '-' || date[7] != '-'){
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
        return false;
    }
    unsigned short monthlen[]={31,28,31,30,31,30,31,31,30,31,30,31};
   
    if ((!(tmpYear%4) && (tmpYear%100)) || !(tmpYear%400)){ // check if year is a leap year
        monthlen[1]++;
    }
    if (tmpDay > monthlen[tmpMonth - 1]){
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidValue(const std::string & valueStr) const{
    std::istringstream iss(valueStr);
    float value;
    if (!(iss >> value) || value < 0){
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    else if (value > 1000){
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

float BitcoinExchange::getRateFromData(const std::string & date) const{
    std::multimap<std::string, float>::const_iterator low = _data.lower_bound(date);
    if (low != _data.end() && low->first == date){
        return low->second;
    }
    if (low != _data.begin()){
        --low;
        return low->second;
    }
    return 0.0f;
}

void BitcoinExchange::loadInputFile(const std::string & fileName){
    std::ifstream inputFile;
    std::string line;
    inputFile.open(fileName.c_str());
    if (!inputFile){
        throw std::runtime_error("Error: could not open file");
    }
    if (!std::getline(inputFile, line) || line != "date | value"){
        throw std::runtime_error("Error: invalid input file format");
    }
    while (std::getline(inputFile, line)){
        std::istringstream ss(line);
        std::string date, valueStr;
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)){
            if (!isValidDate(date)){
                std::cerr << "Wrong date format => " << date << std::endl;
                continue;
            }
            date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
            if (!isValidValue(valueStr)){
                continue;
            }
            float value = static_cast<float>(std::atof(valueStr.c_str()));
            float rate = getRateFromData(date);
            std::cout << date << " => " << value << " = " << rate * value << std::endl;
        }
        else
           std::cerr << "Error: bad input => " << line << std::endl;
    }
    inputFile.close();
}
