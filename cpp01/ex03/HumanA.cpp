/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:46:09 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/11 17:29:48 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon &w, std::string name): w(w), name(name){
}

Weapon HumanA::getWeapon(){
	return w;
}

std::string HumanA::getname(){
	return name;
}

void HumanA::attack(){
	std::cout << getname() << " attacks with their " << getWeapon().getType() << std::endl;
}