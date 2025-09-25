/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:14:50 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/29 16:33:51 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>

template <typename T>
class Array
{
	private:
		T *_array;
		size_t _size;
		
	public:
		Array();
		~Array();
		Array(size_t n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		
		T &operator[](size_t n)const;
		class OutOfLimitsException : public std::exception
		{
			const char *what() const throw();
		};
		size_t size() const;		
};

#include "Array.tpp"
