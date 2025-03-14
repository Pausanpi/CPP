/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:42:51 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/11 11:45:26 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

bool is_number(const std::string& s)
{
	for (int i = 0; s[i]; i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return true;
}

int main()
{
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Menu" << std::endl;
		std::cout << "1. ADD" << std::endl;
		std::cout << "2. SEARCH" << std::endl;
		std::cout << "3. EXIT" << std::endl;

		std::string option;
		std::cout << "Select an option: " ;
		std::cin >> option;
		int opt;

		if (option == "ADD")
			opt = 1;
		else if (option == "SEARCH")
			opt = 2;
		else if (option == "EXIT")
			opt = 3;
		else
			opt = 0;


		switch (opt)
		{
		case 1:
		{
			std::string name, lastname, nick, phone, secret;
			
			do {
				std::cout << "Name: ";
				std::cin >> name;
				if (name.empty())
					std::cout << "Invalid. Empty field" << std::endl;
			} while (name.empty());
			
			do {
				std::cout << "Last name: ";
				std::cin >> lastname;
				if (lastname.empty())
					std::cout << "Invalid. Empty field" << std::endl;
			} while (lastname.empty());
			
			do {
				std::cout << "Nickname: ";
				std::cin >> nick;
				if (nick.empty())
					std::cout << "Invalid. Empty field" << std::endl;
			}while (nick.empty());

			do {
				std::cout << "Phone: ";
				std::cin >> phone;
				if (!is_number(phone))
					std::cout << "Must contain only numbers" << std::endl;
			} while (!is_number(phone));
			
			do {
				std::cout << "Dark secret: ";
				std::cin >> secret;
				if (secret.empty())
					std::cout << "Invalid. Empty field" << std::endl;
			} while (secret.empty());

			Contact newContact(name, lastname, nick, phone, secret);
			phonebook.add_contact(newContact);
			break;	
		}
		case 2:
			std::cout << std::endl;
			phonebook.search_contact();
			break;
			
		case 3:
			std::cout << "Leaving the program..." << std::endl;
			return (0);
		
		default:
			std::cout << "Invalid option" << std::endl;
			break;
		}
	}
	return (0);
}