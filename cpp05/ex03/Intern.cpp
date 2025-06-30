/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:57:25 by pausanch          #+#    #+#             */
/*   Updated: 2025/05/08 16:09:32 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
	*this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other){
    (void) other;
    return (*this);
}

AForm* Intern::makeForm(std::string form, std::string target)
{
	AForm *f = NULL;
	std::string forms[3] = {"presidential", "robotomy", "shrubbery"};
	int i = 0;
	
	while (i < 3)
	{
		if (forms[i] == form)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
		{
				f = new PresidentialPardonForm(target);
				std::cout << "Intern creates a " << form << " form.\n";
				break;
		}
		case 1:
		{
				f = new RobotomyRequestForm(target);
				std::cout << "Intern creates a " << form << " form.\n";
				break;
		}
		case 2:
		{
				f = new ShrubberyCreationForm(target);
				std::cout << "Intern creates a " << form << " form.\n";
				break;
		}
		default:
				std::cout << "Intern tries to create a " << form << " form, but it doesn't exits.\n";
	}
	return (f);
}