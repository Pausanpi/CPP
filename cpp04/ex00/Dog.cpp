/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:41:38 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 14:44:32 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy){
	*this = copy;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy){
	this->type = copy.type;
	return *this;
}

void Dog::makeSound() const{
	std::cout << "Woof" << std::endl;
}