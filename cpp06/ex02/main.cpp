/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:52:29 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/28 15:42:29 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base *obj = generate();
	
	std::cout << "Identify by pointer: ";
	identify(obj);
	
	std::cout << "Identify by reference: ";
	identify(*obj);
	
	delete obj;
	return 0;
}