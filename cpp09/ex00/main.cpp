/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 11:57:25 by pausanch          #+#    #+#             */
/*   Updated: 2025/08/06 15:22:11 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char** argv){
	if (argc != 2){
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	BitcoinExchange	bitcoin(argv[1]);
}