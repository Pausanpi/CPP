/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:42:51 by pausanch          #+#    #+#             */
/*   Updated: 2024/11/07 15:22:03 by pausanch         ###   ########.fr       */
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
		std::cout << "Selecciona una opcion: " ;
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
				std::cout << "Nombre: ";
				std::cin >> name;
				if (name.empty())
					std::cout << "Invalido. Campo vacio" << std::endl;
			} while (name.empty());
			
			do {
				std::cout << "Apellido: ";
				std::cin >> lastname;
				if (lastname.empty())
					std::cout << "Invalido. Campo vacio" << std::endl;
			} while (lastname.empty());
			
			do {
				std::cout << "Apodo: ";
				std::cin >> nick;
				if (nick.empty())
					std::cout << "Invalido. Campo vacio" << std::endl;
			}while (nick.empty());

			do {
				std::cout << "Telefono: ";
				std::cin >> phone;
				if (!is_number(phone))
					std::cout << "Solo debe contener numeros" << std::endl;
			} while (!is_number(phone));
			
			do {
				std::cout << "Secreto: ";
				std::cin >> secret;
				if (secret.empty())
					std::cout << "Invalido. Campo vacio" << std::endl;
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
			std::cout << "Saliendo del programa..." << std::endl;
			return (0);
		
		default:
			std::cout << "Opcion invalida" << std::endl;
			break;
		}
	}
	return (0);
}