/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:39:04 by asemykin          #+#    #+#             */
/*   Updated: 2025/10/18 14:31:17 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>        // for time..

// init static members of Account(not in the constructor)
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// _accountIndex    = unique ID for the account
// _nbAccounts      = how many accounts exist so far(class_wide, static)
// _amount          = the balance of the account
// initial_deposit  = passed to the constructor when creating the account

Account::Account(int initial_deposit)
{
  	_accountIndex = _nbAccounts;    // giving the account a sequential index starting at 0
	_amount = initial_deposit;      // sets the starting balance of the account
	_nbDeposits = 0;
	_nbWithdrawals = 0; 
    
    _nbAccounts++;                  // always increment after new account
    _totalAmount += _amount;        // update total amount of all accounts

    _displayTimestamp();
    std::cout   << " index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "created" 
                << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout   << " index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "closed" 
                << std::endl;
}

void Account::_displayTimestamp()
{
    std::time_t ts;
    struct std::tm dt;
    char dts[18];
    
    ts = time(NULL);
    dt = *localtime(&ts);
    std::strftime(dts, 18, "[%Y%e%m_%I%M%S]", &dt);
    std::cout << dts;
}

void Account::makeDeposit( int deposit )
{
    int p_amount = _amount;
    _amount += deposit;
    _totalAmount += _amount;
    _nbDeposits++;
    _totalNbDeposits++;
    
    _displayTimestamp();
    std::cout   << " index:" << _accountIndex << ";"
                << "p_amount:" << p_amount << ";"
                << "deposit:" << deposit << ";"
                << "amount:" << _amount << ";"
                << "nb_deposits:" << _nbDeposits 
                << std::endl; 
}

bool Account::makeWithdrawal( int withdrawal )
{
    int p_amount = _amount;
    
    if(_amount < withdrawal)
    {
        _displayTimestamp();
        std::cout   << " index:" << _accountIndex << ";"
                    << "p_amount:" << p_amount << ";"
                    << "withdrawal:refused" 
                    << std::endl;
        return false;
    }
    else
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        
        _displayTimestamp();
        std::cout   << " index:" << _accountIndex << ";"
                    << "p_amount:" << p_amount << ";"
                    << "withdrawal:" << withdrawal << ";"
                    << "amount:" << _amount << ";"
                    << "withdrawals:" << _nbWithdrawals 
                    << std::endl;
        return true; 
    }
}

int Account::checkAmount( void )const
{
    return _amount;
}

void Account::displayStatus( void )const
{
    _displayTimestamp();
    std::cout   << " index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals 
                << std::endl;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout   << " accounts:" << _nbAccounts << ";"
                << "total:" << _totalAmount << ";"
                << "deposits:" << _totalNbDeposits << ";"
                << "withdrawals:" << _totalNbWithdrawals 
                << std::endl;
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
