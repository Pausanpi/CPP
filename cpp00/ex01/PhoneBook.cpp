/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:42:53 by pausanch          #+#    #+#             */
/*   Updated: 2025/03/11 11:43:07 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void PhoneBook::add_contact(Contact &contact)
{
	if (numContacts < MAX_CONTACTS)
	{
		contacts[numContacts++] = contact;
		std::cout << "Contact added!" << std::endl;
	}
	else
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
			contacts[i] = contacts[i + 1];
		contacts[7] = contact;
		std::cout << "Address book full. The last oldest contact has been deleted." << std::endl;
	}
}

void PhoneBook::search_contact()
{
    if (numContacts == 0)
    {
        std::cout << "No contacts are saved." << std::endl;
        return;
    }

    std::cout << std::endl << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '-') << std::endl;

    for (int i = 0; i < numContacts; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].get_first_name()) << "|"
                  << std::setw(10) << truncate(contacts[i].get_last_name()) << "|"
                  << std::setw(10) << truncate(contacts[i].get_nickname()) << std::endl;
    }

    int index;

	while(1) {
    	std::cout << std::endl << "Enter the index of the contact to display: ";
    	std::cin >> index;
		if (std::cin.fail() || index < 0 || index >= numContacts)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong index." << std::endl;
		}
		else
		{
			break;
		}
	}

    if (std::cin.fail() || index < 0 || index >= numContacts)
    {
        std::cin.clear();
        std::cout << "Invalid index." << std::endl;
    }
    else
    {
        std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
        std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
        std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
		std::cout << "Phone: " << contacts[index].get_phone_number() << std::endl;
		std::cout << "Secret: " << contacts[index].get_darkest_secret() << std::endl << std::endl;
    }
}

std::string PhoneBook::truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}