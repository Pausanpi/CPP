/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:02:41 by pausanch          #+#    #+#             */
/*   Updated: 2025/04/24 12:24:41 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	*b1 = NULL;
	Bureaucrat	*b2 = NULL;
	Bureaucrat	*b3 = NULL;
	Form		*f1 = NULL;
	Form		*f2 = NULL;
	try
	{
		b1 = new Bureaucrat("Antonio", 149);
		b2 = new Bureaucrat("Juan", 26);
		b3 = new Bureaucrat(*b1);
		f1 = new Form("B1", 150, 100);
		f2 = new Form("B2", 25, 75);
		
		std::cout << "b3 :" << *b3 <<std::endl;
		*b3 = *b2;
		std::cout << "b3 :" << *b3 <<std::endl;
		b1->decrementGrade();
		b1->signForm(*f1);
		b1->signForm(*f2);
		b2->signForm(*f1);
		b2->incrementGrade();
		b2->signForm(*f2);
		std::cout << "\nb1: " << *b1 << "\n" << "b2: " << *b2 << std::endl;
		std::cout << *f1 << "\n" << *f2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete b1;
	delete b2;
	delete b3;
	delete f1;
	delete f2;
}