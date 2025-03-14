/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:46:11 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/11 17:21:12 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *w;
		std::string name;
		
	public:
		HumanB(){}
		HumanB(std::string name);
		~HumanB(){}
		std::string getname();
		void attack();
		void setWeapon(Weapon &w);
		
};