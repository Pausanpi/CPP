/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:27:15 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/11 16:32:55 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *hordita;
	hordita = zombieHorde(5, "Antonio");
	for(int i = 0; i < 5; i++)
		hordita[i].announce();
	delete[] hordita;
}