/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:02:41 by pausanch          #+#    #+#             */
/*   Updated: 2025/04/09 12:43:10 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
    try
    {
        Bureaucrat bur("Peter", 0);
        std::cout << bur << std::endl;
        bur.incrementGrade();
    }
    catch(Bureaucrat::GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bur("Nekane", 1);
        std::cout << bur << std::endl;
        bur.incrementGrade();
    }
    catch(Bureaucrat::GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bur("Laureano", 150);
        std::cout << bur << std::endl;
        bur.decrementGrade();
    }
    catch(Bureaucrat::GradeTooLowException& e){
        std::cout << e.what() << std::endl;
    } 

    return 0;
}