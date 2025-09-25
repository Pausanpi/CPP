/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:30:08 by pausanch          #+#    #+#             */
/*   Updated: 2025/07/25 13:36:18 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}
	
Serializer::Serializer(const Serializer &src)
{
	(void)src;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	return *this;
}

uintptr_t Serializer::serialize(Data* data)
{
	return reinterpret_cast<uintptr_t>(data);
}

Data* Serializer::deserialize(const uintptr_t& str)
{
	return reinterpret_cast<Data*>(str);
}