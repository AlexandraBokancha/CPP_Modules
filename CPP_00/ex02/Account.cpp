#include "Account.hpp"
#include <iostream>

// on les initialise ici parce qu'ils sont static (donc ils 
// sont initialise qu'une fois,
// pendant le premier appel de la fonction)

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// constructor

Account::Account( int initial_deposit )
{
    _amount = initial_deposit;
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" \
    << "amount:" << _amount << ";" \
    << "created" << std::endl;
    return;
};
// simple "getters" pour les membres privees

int	Account::getNbAccounts( void ){
    return (_nbAccounts);
};

int	Account::getTotalAmount( void ){
    return (_totalAmount);
};

int	Account::getNbDeposits( void ){
    return (_totalNbDeposits);
};

int Account::getNbWithdrawals( void ){
    return (_totalNbWithdrawals);
};

// fonction pour avoir YYMMDD_HHMMSS format

void	Account::_displayTimestamp( void )
{
    time_t  now = time(0);
    struct tm datetime;
    static char    format[32];

    datetime = *localtime(&now);
    strftime(format, 32, "[%Y%m%d_%H%M%S] ", &datetime);
    std::cout << format;
    return ;
};

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

void Account::displayAccountsInfos( void ){
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";" \
    << "total:" << _totalAmount << ";" \
    << "deposits:" << getNbDeposits() << ";" \
    << "withdrawals:" << getNbWithdrawals() << std::endl;
    return ;
};

// c'est une fonction constante - donc les donnees des membres
// de la classe ne peuvent pas etre modifiees (pareil pour checkAmount)

void	Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" \
    << "amount:" << _amount << ";" \
    << "deposits:" << _nbDeposits << ";" \
    << "withdrawals:" << _nbWithdrawals << std::endl;
    return ;
};

// format : [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1

void	Account::makeDeposit( int deposit ){
    int p_amount = _amount;
    
     _displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    std::cout << "index:" << _accountIndex << ";" \
    << "p_amount:" << p_amount << ";" \
    << "deposit:" << deposit << ";" \
     << "amount:" << _amount << ";" \
    << "nb_deposits:" << _nbDeposits << std::endl;
    return ;
};

int		Account::checkAmount( void ) const{
    return (_amount);
};

//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1

bool	Account::makeWithdrawal( int withdrawal ){
    int p_amount = _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" \
    << "p_amount:" << p_amount << ";";
    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    else if (withdrawal <= _amount)
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << "withdrawal:" << withdrawal << ";" \
        << "amount:" << _amount << ";" \
        << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    }
    return (true);
};

// deconstructor

Account::~Account(){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" \
    << "amount:" << _amount << ";" \
    << "closed" << std::endl;
    return;
};
