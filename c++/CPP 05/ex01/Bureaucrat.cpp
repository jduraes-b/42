/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:42:14 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/27 19:38:21 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name (name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 151 && grade > 0)
		_grade = grade;
	else
		grade = 150;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string&	Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::signForm(Form &f)
{
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getFormName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << _name << " couldn't sign " << f.getFormName();
		std::cout << " because they lack the required grade" << std::endl;	
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high.\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.\n";
}

void	Bureaucrat::print(std::ostream& os) const
{
	os << _name << ", bureaucrat grade " << _grade << ".";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	b.print(os);
	return os;
}
