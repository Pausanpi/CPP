/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:47:08 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 14:57:33 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		~WrongCat();
		WrongCat &operator=(const WrongCat &copy);
		
		void makeSound() const;	
};