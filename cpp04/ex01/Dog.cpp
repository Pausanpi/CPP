/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:41:38 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 15:15:31 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()){
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy), brain(new Brain(*copy.brain)){
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(){
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy){
	std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &copy) {
        Animal::operator=(copy);
        *brain = *copy.brain;
    }
    return *this;
}

void Dog::makeSound() const{
	std::cout << "Woof" << std::endl;
}