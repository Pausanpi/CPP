/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:24:23 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/30 12:20:05 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>

class NotFound : public std::exception
{
	public:
		const char *what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &container, int value);

#include "easyfind.tpp"