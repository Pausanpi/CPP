/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:52:29 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/25 13:46:35 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data* data = new Data;
	data->str = "Test";
	
	std::cout << "Original: " << data << ", Texto Original: " << data->str << std::endl;
	
	uintptr_t serialized = Serializer::serialize(data);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Deserialized: " << deserialized << ", Texto Deserializado: " << deserialized->str << std::endl;
	std::cout << "Same? " << (data == deserialized ? "Yes" : "No") << std::endl;
	
	delete data;
	return 0;
}