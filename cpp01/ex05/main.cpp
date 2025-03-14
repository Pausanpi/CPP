/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:43:25 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/12 13:08:40 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Testing " << VERDE << "DEBUG "<< RESET << "level:" << std::endl;
    harl.complain("DEBUG");

    std::cout << "\nTesting " << AMARILLO << "INFO "<< RESET << "level:" << std::endl;
    harl.complain("INFO");

    std::cout << "\nTesting " << NARANJA << "WARNING "<< RESET << "level:" << std::endl;
    harl.complain("WARNING");

    std::cout << "\nTesting " << ROJO << "ERROR "<< RESET << "level:" << std::endl;
    harl.complain("ERROR");

    std::cout << "\nTesting invalid level:" << std::endl;
    harl.complain("NOT_A_LEVEL");

    return 0;
}