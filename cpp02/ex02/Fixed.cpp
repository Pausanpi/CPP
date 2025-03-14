/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:13:35 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/12 16:28:42 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	/* std::cout << "Default constructor called" << std::endl; */
}

Fixed::Fixed(const int value)
{
	/* std::cout << "Int constructor called" << std::endl; */
	this->value = value << bits;
}

Fixed::Fixed(const float value)
{
	/* std::cout << "Float constructor called" << std::endl; */
	this->value = roundf(value * (1 << bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	/* std::cout << "Copy constructor called" << std::endl; */
	*this = fixed;
}

Fixed::~Fixed()
{
	/* std::cout << "Destructor called" << std::endl; */
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	/* std::cout << "Assignation operator called" << std::endl; */
	this->value = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->value / (1 << bits);
}

int Fixed::toInt(void) const
{
	return this->value >> bits;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return this->value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return this->value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return this->value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return this->value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return this->value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return this->value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}