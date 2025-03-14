/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:47:01 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 14:56:06 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type){
	this->type = type;
}

WrongAnimal::~WrongAnimal(){
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy){
	this->type = copy.type;
	return (*this);
}

std::string WrongAnimal::getType() const{
	return (this->type);
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal sound" << std::endl;
}