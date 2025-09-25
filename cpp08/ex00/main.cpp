/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:18:56 by pausanch          #+#    #+#             */
/*   Updated: 2025/09/10 11:40:58 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::cout << "Vector contents: ";
	for (unsigned long i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	try {
		std::cout << "Look for number 2: ";
		easyfind(vec, 2);
		std::cout << "Found!" << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Look for number 5: ";
		easyfind(vec, 5);
		std::cout << "Found!" << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	std::cout << "List contents: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	try {
		std::cout << "Look for number 2: ";
		easyfind(lst, 2);
		std::cout << "Found!" << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Look for number 5: ";
		easyfind(lst, 5);
		std::cout << "Found!" << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}