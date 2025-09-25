/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:14:52 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/25 13:42:46 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	std::string str;
};

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		
	public:
		static uintptr_t serialize(Data* data);
		static Data* deserialize(const uintptr_t& str);
};