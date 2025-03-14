/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:22:19 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 12:23:50 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public:
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		
		void highFivesGuys(void);
	
};