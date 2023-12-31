/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:36:31 by jutrera-          #+#    #+#             */
/*   Updated: 2023/07/08 13:45:16 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

// La definición e inicialización de la variable estática debe realizarse fuera de la clase,
//   en el ámbito global, para asegurar que haya una única instancia de la variable compartida 
//   por todos los objetos de la clase.
int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( void )
{

}

Account::Account(int initial_deposit) 
{
	static int i = 0;

    _nbAccounts++;
	_accountIndex = i++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created" << std::endl;
}

Account::~Account( void ) 
{
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed" << std::endl;
}

int Account::checkAmount( void ) const 
{
    return _amount;
}

int Account::getNbAccounts( void ) 
{
    return _nbAccounts;
}

int Account::getTotalAmount( void ) 
{
    return _totalAmount;
}

int Account::getNbDeposits( void ) 
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) 
{
    return _totalNbWithdrawals;
}

// We need to remove the "static" keyword because the compiler knows it's a static class method
void Account::_displayTimestamp()
{
    std::time_t result = std::time(NULL);

    std::cout << std::setfill('0') <<"[" 
			  << 1900 + std::localtime(&result)->tm_year
              << std::setw(2) << 1 + std::localtime(&result)->tm_mon
              << std::setw(2) << std::localtime(&result)->tm_mday
              << "_"
              << std::setw(2) << std::localtime(&result)->tm_hour
              << std::setw(2) << std::localtime(&result)->tm_min
              << std::setw(2) << std::localtime(&result)->tm_sec 
              << "] " << std::flush;
}

void    Account::displayAccountsInfos( void ) 
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << getNbDeposits() << ";"
              << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void    Account::makeDeposit( int deposit ) 
{
    this->_displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";" 
			  << "deposit:" << deposit << ";" << std::flush;
    _amount += deposit;
    std::cout << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal ) 
{
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";" << std::flush;
    if (withdrawal > checkAmount()) 
    {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    std::cout << "withdrawal:" << withdrawal << ";" 
			  << "amount:" << _amount << ";"
              << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

void    Account::displayStatus( void ) const 
{
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << std::endl;
}	