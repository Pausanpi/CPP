/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:47:04 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 14:57:06 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy){
	*this = copy;
}

WrongCat::~WrongCat(){
}

WrongCat &WrongCat::operator=(const WrongCat &copy){
	this->type = copy.type;
	return (*this);
}

void WrongCat::makeSound() const{
	std::cout << "WrongCat sound" << std::endl;
}
