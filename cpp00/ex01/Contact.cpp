/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:42:58 by pausanch          #+#    #+#             */
/*   Updated: 2024/11/07 14:46:22 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_first_name() const
{
	return first_name;
}

std::string Contact::get_last_name() const
{
	return last_name;
}

std::string Contact::get_nickname() const
{
	return nickname;
}

std::string Contact::get_phone_number() const
{
	return phone_number;
}

std::string Contact::get_darkest_secret() const
{
	return darkest_secret;
}