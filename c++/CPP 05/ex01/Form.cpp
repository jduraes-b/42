/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:14:59 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/09 18:30:58 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _issigned(0), _signreq(150), _execreq(150)
{
}

Form::Form(std::string name, int sign, int exec) : _name(name), _issigned(0), _signreq(sign), _execreq(exec)
{
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _issigned(other._issigned), _signreq(other._signreq), _execreq(other._execreq)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_issigned = other._issigned;	
	return (*this);
}

Form::~Form()
{
}

int Form::getSignReq() const
{
	return (_signreq);
}

std::string	Form::getFormName() const
{
	return (_name);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _signreq)
		throw GradeTooLowException();
	else
		this->_issigned = 1;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low.\n";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.\n";
}

void	Form::print(std::ostream& os) const
{	
	if (_issigned == 1)
		os << "Signed ";
	else
		os << "Unsigned ";
	os << "form \"" << _name << "\" requires grade " << _signreq;
	os << " to sign and grade " << _execreq << " to execute.";

}
std::ostream& operator<<(std::ostream &os, const Form &f)
{
	f.print(os);
	return (os);
}
