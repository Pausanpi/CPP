/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:41:31 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 15:21:48 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), brain(new Brain()){
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy): AAnimal(copy), brain(new Brain(*copy.brain)){
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(){
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy){
	std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &copy) {
        AAnimal::operator=(copy);
        *brain = *copy.brain;
    }
    return *this;
}

void Cat::makeSound() const{
	std::cout << "Meow" << std::endl;
}