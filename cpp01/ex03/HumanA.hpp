/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:46:06 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/11 17:29:59 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon &w;
		std::string name;
		
	public:
		HumanA();
		HumanA(Weapon &w, std::string name);
		~HumanA(){}
		Weapon getWeapon();
		std::string getname();
		void attack();
		
};

#endif