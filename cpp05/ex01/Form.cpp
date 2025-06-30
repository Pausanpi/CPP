/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:50:33 by pausanch          #+#    #+#             */
/*   Updated: 2025/05/08 15:24:59 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150) {
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) {
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) : name(src.name), is_signed(src.is_signed), grade_to_sign(src.grade_to_sign), grade_to_execute(src.grade_to_execute) {
}

Form::~Form() {
}

Form &Form::operator=(const Form &src) {
	if (this != &src) {
		this->is_signed = src.is_signed;
	}
	return *this;
}

std::string Form::getName() const {
	return this->name;
}

bool Form::getSigned() const {
	return this->is_signed;
}

int Form::getGradeToSign() const {
	return this->grade_to_sign;
}

int Form::getGradeToExec() const {
	return this->grade_to_execute;
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->grade_to_sign)
		throw Form::GradeTooLowException();
	this->is_signed = true;
	std::cout << b.getName() << " signed " << this->name << std::endl;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& o, const Form& f) {
	o << "Form: " << f.getName() << ", is_signed: " << f.getSigned() << ", grade_to_sign: " << f.getGradeToSign() << ", grade_to_execute: " << f.getGradeToExec();
	return o;
}