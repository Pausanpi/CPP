/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:51:04 by pausanch          #+#    #+#             */
/*   Updated: 2024/11/11 11:51:04 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{	
	private:
		std::string name;

	public:
		Zombie() {}
		Zombie(std::string name);
		~Zombie();
		void announce();
		void set_name(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif