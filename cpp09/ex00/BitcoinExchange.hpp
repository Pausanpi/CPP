/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:12:52 by pausanch          #+#    #+#             */
/*   Updated: 2025/08/06 15:11:40 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

	public:
		BitcoinExchange(const std::string &filename);
		~BitcoinExchange();

		void loadData();
		void manageInput(std::string input);
		void printResult(std::string str);
};