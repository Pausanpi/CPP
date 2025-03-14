/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:41:31 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 14:59:44 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy){
	*this = copy;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy){
	this->type = copy.type;
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Meow" << std::endl;
}