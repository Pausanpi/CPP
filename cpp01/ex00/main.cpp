/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:50:30 by pausanch          #+#    #+#             */
/*   Updated: 2024/11/11 11:50:30 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void){
	Zombie z("Nekane");
	Zombie*	newZ;

	z.announce();
	newZ = newZombie("Antonio");
	newZ->announce();
	randomChump("Laureano");
	randomChump("Pepa");
	delete newZ;
	return 0;
}