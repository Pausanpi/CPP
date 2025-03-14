/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:27:26 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/13 11:58:25 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){

    ClapTrap clap1("Nekane");
    ClapTrap clap2("Laureano");

    clap1.attack("target");
    clap2.attack("target");

    clap1.takeDamage(5);
    clap1.takeDamage(6);

    clap2.takeDamage(3);
    clap2.beRepaired(5);
    clap2.beRepaired(5);

    for (int i = 0; i < 10; ++i) {
        clap2.attack("target");
    }
    clap2.beRepaired(5);

    ClapTrap clap3(clap2);
    clap3.attack("target");
    clap1.attack("target");

    return 0;
}