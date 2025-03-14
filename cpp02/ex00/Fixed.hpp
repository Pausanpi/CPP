/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:34:54 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/12 15:57:10 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed{
	private:
		int value;
		static const int bits = 8;

	public:
		Fixed();
		Fixed(const Fixed&);
		Fixed& operator=(const Fixed&);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};