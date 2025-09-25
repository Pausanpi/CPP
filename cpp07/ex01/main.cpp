/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:20:04 by pausanch          #+#    #+#             */
/*   Updated: 2025/08/27 12:02:18 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {

	std::cout << "test1: ";
	std::string str = "Hello!";
	::iter(str.c_str(), str.length(), printer<char>);
	std::cout << std::endl;
	std::cout << "test2: ";
	int arr[5] = {0, 1, 2, 3, 4};
	::iter(arr, 5, printer<int>);
	std::cout << std::endl;
}