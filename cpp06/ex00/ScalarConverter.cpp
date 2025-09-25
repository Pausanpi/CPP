/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:06:15 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/24 12:CHAR0:15 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

static void fromPseudo(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "-inff" || str == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (str == "+inff" || str == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

static void fromChar(std::string str)
{
	char c = str[0];
	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	int i = static_cast<int>(c);
	std::cout << "int: " << i << std::endl;

	float f = static_cast<float>(c);
	std::cout << "float: " << f << ".0f" << std::endl;

	double d = static_cast<double>(c);
	std::cout << "double: " << d << ".0" << std::endl;
}

static void fromInt(std::string str)
{
	long int num = std::atol(str.c_str());

	std::cout << "char: ";
	if (num < CHAR_MIN || num > CHAR_MAX || num < 0)
		std::cout << "impossible" << std::endl;
	else if (num < 32 || num > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;

	std::cout << "int: ";
	if (num < INT_MIN || num > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << num << std::endl;

	std::cout << "float: ";
	if (num < INT_MIN)
		std::cout << (INT_MIN) << ".0f" << std::endl;
	else if (num > INT_MAX)
		std::cout << (INT_MAX) << ".0f" << std::endl;
	else
		std::cout << num << ".0f" << std::endl;

	std::cout << "double: ";
	if (num < INT_MIN)
		std::cout << (INT_MIN) << ".0" << std::endl;
	else if (num > INT_MAX)
		std::cout << (INT_MAX) << ".0" << std::endl;
	else
		std::cout << num << ".0" << std::endl;
}

static void fromFloat(std::string str)
{
	double num = std::atof(str.c_str());

	std::cout << "char: ";
	if (num < CHAR_MIN || num > CHAR_MAX || num < 0)
		std::cout << "impossible" << std::endl;
	else if (num < 32 || num > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;

	std::cout << "int: ";
	if (num < INT_MIN || num > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << num << std::endl;
	
	std::cout << "float: ";
	if (isinf(static_cast<float>(num)) && num > 0)
		std::cout << "+inff" << std::endl;
	else if (isinf(static_cast<float>(num)) && num < 0)
		std::cout << "-inff" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;

	std::cout << "double: ";
	if (isinf(num) && num > 0)
		std::cout << "+inf" << std::endl;
	else if (isinf(num) && num < 0)
		std::cout << "-inf" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << num << std::endl;
}

static void fromDouble(std::string str)
{
	double num = std::atof(str.c_str());

	std::cout << "char: ";
	if (num < CHAR_MIN || num > CHAR_MAX || num < 0)
		std::cout << "impossible" << std::endl;
	else if (num < 32 || num > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;

	std::cout << "int: ";
	if (num < INT_MIN || num > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;

	std::cout << "float: ";
	if (isinf(static_cast<float>(num)) && num > 0)
		std::cout << "+inff" << std::endl;
	else if (isinf(static_cast<float>(num)) && num < 0)
		std::cout << "-inff" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;

	std::cout << "double: ";
	if (isinf(num) && num > 0)
		std::cout << "+inf" << std::endl;
	else if (isinf(num) && num < 0)
		std::cout << "-inf" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << num << std::endl;
}

static int getType(const std::string &str)
{
	if (str == "nanf" || str == "-inff" || str == "+inff" || str == "nan" || str == "-inf" || str == "+inf")
		return (PSEUDO);
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (CHAR);

	char *endptr;

	strtol(str.c_str(), &endptr, 10);
	if (str[0] && endptr[0] == '\0')
	{
		return (INT);
	}

	strtod(str.c_str(), &endptr);
	if (endptr[0] == 'F' || endptr[0] == 'f')
	{
		return (FLOAT);
	}
	else if (endptr[0] == '\0')
	{
		return (DOUBLE);
	}

	return (0);
}

void ScalarConverter::convert(const std::string &str)
{
	int type = getType(str);
	switch (type)
	{
		case PSEUDO:
			fromPseudo(str);
			break;

		case CHAR:
			fromChar(str);
			break;

		case INT:
			fromInt(str);
			break;

		case FLOAT:
			fromFloat(str);
			break;

		case DOUBLE:
			fromDouble(str);
			break;

		default:
			std::cerr << "Error: Invalid literal" << std::endl;
			break;
	}
}