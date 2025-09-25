/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:06:18 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/24 13:00:29 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <climits>

enum scalarTypes
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
};

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
	
	public:
		static void convert(const std::string &literal);
};