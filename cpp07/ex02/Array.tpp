/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:17:25 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/29 16:37:55 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template<typename T>
Array<T>::Array(size_t n) : _array(new T[n]()), _size(n) {}

template<typename T>
Array<T>::Array(const Array &other) : _array(new T[other._size]), _size(other._size)
{
	for (size_t i = 0; i < other._size; i++)
		_array[i] = other._array[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete [] _array;
		_size = other._size;
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return (*this);
}

template<typename T>
T &Array<T>::operator[](size_t n) const
{
	if (n >= _size)
		throw OutOfLimitsException();
	return (_array[n]);
}

template<typename T>
const char *Array<T>::OutOfLimitsException::what() const throw()
{
	return ("Index out of limits");
}

template<typename T>
size_t Array<T>::size() const
{
	return (this->_size);
}
