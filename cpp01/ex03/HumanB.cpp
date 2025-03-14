/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:46:13 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/11 17:26:52 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name){}

std::string HumanB::getname(){
	return name;
}

void HumanB::attack(){
	if (w != NULL)
		std::cout << getname() << " attacks with their " << w->getType() << std::endl;
	else
		std::cout << "You've no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &w){
	this->w = &w;
}