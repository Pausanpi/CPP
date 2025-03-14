/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:43:40 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/12 13:08:33 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

#define VERDE    "\033[38;5;154m"
#define ROJO    "\033[31m"
#define AMARILLO    "\033[33m"
#define NARANJA    "\033[38;5;214m"
#define RESET   "\033[0m"

class Harl{
	private:
		void debug();
		void info();
		void warning();
		void error();

	public:
		void complain(std::string level);
};