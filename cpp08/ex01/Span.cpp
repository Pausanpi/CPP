/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:13:59 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/31 11:46:13 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : n(0) {}

Span::~Span() {}

Span::Span(unsigned int num) : n(num) {}

Span::Span(const Span &other) : n(other.n), vect(other.vect) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		n = other.n;
		vect = other.vect;
	}
	return *this;
}

void Span::addNumber(int num)
{
	if (n > vect.size())
		vect.push_back(num);
	else
		throw std::runtime_error("Already full!");
}

size_t Span::shortestSpan()
{
	if (vect.size() < 2)
		throw std::runtime_error("Error shotestSpan");
	
	std::sort(vect.begin(), vect.end());

	int shortest = vect[1] - vect[0];
	for (size_t i = 0; i < vect.size() - 1; i++)
	{
		if (vect[i + 1] - vect[i] < shortest)
			shortest = vect[i + 1] - vect[i];
	}
	
	return shortest;
}

size_t Span::longestSpan()
{
	if (vect.size() < 2)
		throw std::runtime_error("Error longestSpan");
	std::sort(vect.begin(), vect.end());
	return vect[vect.size() - 1] - vect[0];
}