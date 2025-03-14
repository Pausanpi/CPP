/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:27:26 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 12:28:53 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    
    FragTrap frag1("Fraggy");

    frag1.attack("target");

    frag1.highFivesGuys();

    frag1.takeDamage(40);
    frag1.beRepaired(30);

    for (int i = 0; i < 100; ++i) {
        frag1.attack("enemy");
    }
    frag1.beRepaired(10);
    return 0;
}