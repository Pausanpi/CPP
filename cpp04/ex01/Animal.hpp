/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:40:20 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 15:12:33 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal{
	protected:
		std::string type;
	
	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);
		
		std::string getType() const;
		virtual void makeSound() const;
};