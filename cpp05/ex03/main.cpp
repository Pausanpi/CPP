/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:02:41 by pausanch          #+#    #+#             */
/*   Updated: 2025/05/08 16:10:02 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
    try {
        Intern  randomIntern;
        AForm	*formSh = randomIntern.makeForm("shrubbery", "Butterfree");
        AForm	*formRo = randomIntern.makeForm("robotomy", "Pikachu");
        AForm	*formPr = randomIntern.makeForm("presidential", "Charmander");
        Bureaucrat bureaucrat("Ash", 1);

        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(*formSh);
        bureaucrat.executeForm(*formSh);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(*formRo);
        bureaucrat.executeForm(*formRo);
        bureaucrat.executeForm(*formRo);
        bureaucrat.executeForm(*formRo);
        bureaucrat.executeForm(*formRo);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(*formPr);
        bureaucrat.executeForm(*formPr);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}