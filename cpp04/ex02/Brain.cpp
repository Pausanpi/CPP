/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:16:00 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 15:16:29 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &copy){
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain &Brain::operator=(const Brain &copy){
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &copy){
		for (int i = 0; i < 100; i++){
			ideas[i] = copy.ideas[i];
		}
	}
	return *this;
}