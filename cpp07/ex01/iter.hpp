/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:05:41 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/29 12:20:28 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<typename T, typename func>
void iter(T *array, int lenght, func f) {
	for (int i = 0; i < lenght; ++i) {
		f(array[i]);
	}
}

template<typename T>
void	printer(T c) {

	std::cout << c;
}