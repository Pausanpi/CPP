#include "Account.hpp"
#include <iostream>

// Static members initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_nbDeposits = 0;
int Account::_nbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	_accountIndex = _nbAccounts++;
	_totalAmount += _amount;
	std::cout << "Account created: " << _accountIndex << ", initial deposit: " << _amount << std::endl;
}

Account::~Account() {
	std::cout << "Account closed: " << _accountIndex << ", remaining balance: " << _amount << std::endl;
}

void Account::makeDeposit(int deposit) {
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	std::cout << "Deposit made: " << deposit << ", new balance: " << _amount << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (_amount < withdrawal) {
		std::cout << "Withdrawal failed: insufficient funds" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	std::cout << "Withdrawal made: " << withdrawal << ", new balance: " << _amount << std::endl;
	return true;
}

int Account::checkAmount() const {
	return _amount;
}

void Account::displayStatus() const {
	std::cout << "Account status: " << _accountIndex << ", balance: " << _amount << std::endl;
}

