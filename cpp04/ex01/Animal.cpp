/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:40:11 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 14:45:22 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	this->type = "Animal";
}

Animal::Animal(std::string type){
	this->type = type;
}

Animal::~Animal(){
}

Animal::Animal(const Animal &copy){
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy){
	this->type = copy.type;
	return (*this);
}

std::string Animal::getType() const{
	return (this->type);
}

void Animal::makeSound() const{
	std::cout << "Animal sound" << std::endl;
}
