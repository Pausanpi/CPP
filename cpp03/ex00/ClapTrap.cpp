/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:27:23 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 11:43:46 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name){
	this->name = name;
	this->hitpoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << this->name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->name << " has been destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
	*this = other;
}	

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	this->name = other.name;
	this->hitpoints = other.hitpoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

void ClapTrap::attack(std::string const & target){
	if (hitpoints == 0)
		std::cout << "ClapTrap " << this->name << " is dead and can't attack" << std::endl;
	else if (energyPoints == 0)
		std::cout << "ClapTrap " << this->name << " has no energy and can't attack" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (hitpoints <= 0)
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
	else if (hitpoints - amount <= 0)
	{
		std::cout << "ClapTrap " << this->name << " has taken " << amount << " points of damage and has died" << std::endl;
		hitpoints = 0;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " has taken " << amount << " points of damage!" << std::endl;
		hitpoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (hitpoints <= 0)
		std::cout << "ClapTrap " << this->name << " is dead and can't heal!" << std::endl;
	else if (energyPoints <= 0)
		std::cout << "ClapTrap " << this->name << " has no energy left!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << this->name << " has been repaired " << amount << " points of health!" << std::endl;
		hitpoints += amount;
		energyPoints--;
	}
}
