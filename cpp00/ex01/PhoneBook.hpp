/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:42:55 by pausanch          #+#    #+#             */
/*   Updated: 2024/11/07 15:31:47 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		static const int MAX_CONTACTS = 8;
		Contact contacts[MAX_CONTACTS];
		int numContacts;

	public:
		PhoneBook() :numContacts(0){}
	
		void add_contact(Contact &contact);
		void search_contact();
		std::string truncate(const std::string &str);
};

#endif