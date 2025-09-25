/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:52:56 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/31 11:44:07 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
	private:
		unsigned int n;
		std::vector<int> vect;

	public:
		Span();
		~Span();
		Span(unsigned int num);
		Span(const Span &other);
		Span &operator=(const Span &other);

		void addNumber(int num);
		size_t shortestSpan();
		size_t longestSpan();
};