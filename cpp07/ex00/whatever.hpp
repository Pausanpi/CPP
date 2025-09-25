/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:36:02 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/29 12:01:42 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b= tmp;
}

template<typename T>
T min(const T &a, const T &b)
{
	return a < b ? a : b;
}

template<typename T>
T max(const T &a, const T &b)
{
	return a > b ? a : b;
}