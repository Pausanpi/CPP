/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:22:43 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 12:24:59 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->hitpoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " has been created" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << this->name << " has been destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other){
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->name << " requests a high five" << std::endl;
}