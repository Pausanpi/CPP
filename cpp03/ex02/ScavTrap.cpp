/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:56:35 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 12:09:59 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->hitpoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " has been created" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << this->name << " has been destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other){
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

void ScavTrap::attack(std::string const & target){
	if (hitpoints <= 0)
		std::cout << "ScavTrap " << this->name << " is dead and can't attack" << std::endl;
	else if (energyPoints <= 0)
		std::cout << "ScavTrap " << this->name << " has no energy and can't attack" << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
}