/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:33:30 by pausanch          #+#    #+#             */
/*   Updated: 2025/09/23 14:34:15 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	loadData();
	manageInput(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	this->_data = other._data;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_data = other._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData()
{
	std::ifstream file("data.csv");
	std::string date;
	float value;
	
	if (!file.is_open())
	{
		std::cerr << "Error: could not open data file." << std::endl;
		return;
	}
	
	std::getline(file, date);
	if (date.empty())
	{
		std::cerr << "Error: data file is empty." << std::endl;
		file.close();
		return;
	}	
	
	while (file.good())
	{
		if (!std::getline(file, date))
		{
			//std::cerr << "Error: problem reading date from file." << std::endl;
			file.close();
			return;
		}

		value = atof(date.substr(date.find(',') + 1, date.length()).c_str());
		date = date.substr(0, date.find(','));
		this->_data[date] = value;
	}
	file.close();
}

static int checkDateFormat(const std::string &date)
{
	if (date.length() != 11 || date[4] != '-' || date[7] != '-')
		return 1;
		
	int day = std::atoi(date.substr(8, 10).c_str());
	int month = std::atoi(date.substr(5, 7).c_str());
	int year = std::atoi(date.substr(0, 4).c_str());
	int arrayDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month < 1 || month > 12)
		return 1;
	if (day < 1 || day > arrayDays[month - 1])
		return 1;
	if (month == 2 && day == 29 && year % 4 != 0)
		return 1;
	return 0;
}

static int checkCoins(std::string coins)
{
	if (atof(coins.c_str()) > 1000)
		return 3;
	for (size_t i = 0; i < coins.length(); i++){
		if ((!isdigit(coins[i]) && coins[i] != '.') || (coins.find_first_of('.') != coins.find_last_of('.')) || (coins[i] == '.' && i == 0)){
			if (coins[i] == '-' && coins.find_last_of('-') == i && i == 0)
				return 2;
			else
				return 1;
		}
	}
	return 0;
}
		
static int checkInput(std::string str)
{
	if (str.empty() || str[0] == '\n')
		return 4;
	if (str.find('|') == str.npos || str.find('-') == str.npos)
		return 1;
	std::string data = str.substr(0, str.find('|'));
	if (checkDateFormat(data))
		return 1;
	std::string coins = str.substr(str.find('|') + 2, str.length());
	if (coins.empty())
		return 1;
	return (checkCoins(coins));
}

void BitcoinExchange::manageInput(std::string input)
{
	std::ifstream file(input.c_str());
	std::string str;

	if (!file.is_open())
	{
		std::cerr << "Error: Could not open input file." << std::endl;
		return;
	}

	while (file.good())
	{
		if (!std::getline(file, str))
		{
			std::cerr << "Error: Problem reading line from input file." << std::endl;
			file.close();
			return;
		}
		if (str == "date | value")
			continue;
		switch(checkInput(str))
		{
			case 1:
				std::cerr << "Error: bad imput => " << str << std::endl;
				break;

			case 2:
				std::cerr << "Error: not a positive number." << std::endl;
				break;

			case 3:
				std::cerr << "Error: too large a number." << std::endl;
				break;

			case 4:
				break;

			default:
				printResult(str);
				break;
		}
	}
}

void BitcoinExchange::printResult(std::string str)
{
	std::map<std::string, float>::const_iterator it = _data.begin();
	std::string date = str.substr(0, str.find('|') - 1);
	float coins = atof(str.substr(str.find('|') + 1, str.length()).c_str());

	if (date < it->first)
		std::cerr << "Error: Data not found." << std::endl;
	else
	{
		it = this->_data.lower_bound(date);
		if (it->first != date)
			it--;
		std::cout << date << " => " << coins << " = " << coins * it->second << std::endl;
	}
}