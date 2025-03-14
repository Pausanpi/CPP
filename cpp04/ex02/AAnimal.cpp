/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:40:11 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 14:45:22 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal"){
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type){
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy){
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &copy){
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

std::string AAnimal::getType() const{
	return (this->type);
}

void AAnimal::makeSound() const{
	std::cout << "AAnimal sound" << std::endl;
}
