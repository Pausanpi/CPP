/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pausanch <pausanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:50:33 by pausanch          #+#    #+#             */
/*   Updated: 2025/04/15 12:10:05 by pausanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150) {
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) {
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src) : name(src.name), is_signed(src.is_signed), grade_to_sign(src.grade_to_sign), grade_to_execute(src.grade_to_execute) {
}

AForm::~AForm() {
}

AForm &AForm::operator=(const AForm &src) {
	if (this != &src) {
		this->is_signed = src.is_signed;
	}
	return *this;
}

std::string AForm::getName() const {
	return this->name;
}

bool AForm::getSigned() const {
	return this->is_signed;
}

int AForm::getGradeToSign() const {
	return this->grade_to_sign;
}

int AForm::getGradeToExec() const {
	return this->grade_to_execute;
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->grade_to_sign)
		throw AForm::GradeTooLowException();
	this->is_signed = true;
	std::cout << b.getName() << " signed " << this->name << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::NotSignedException::what() const throw() {
	return "Form not signed";
}

std::ostream& operator<<(std::ostream& o, const AForm& f) {
	o << "AForm: " << f.getName() << ", is_signed: " << f.getSigned() << ", grade_to_sign: " << f.getGradeToSign() << ", grade_to_execute: " << f.getGradeToExec();
	return o;
}