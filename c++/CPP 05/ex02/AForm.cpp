/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:14:59 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/04 18:42:55 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default AForm"), _issigned(0), _signreq(150), _execreq(150)
{
}

AForm::AForm(std::string name, int sign, int exec) : _name(name), _issigned(0), _signreq(sign), _execreq(exec)
{
	if (sign < 1 || exec < 1)
		throw GradeTooHighException();
	if (sign > 150 || exec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _issigned(other._issigned), _signreq(other._signreq), _execreq(other._execreq)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_issigned = other._issigned;	
	return (*this);
}

AForm::~AForm()
{
}

int AForm::getSignReq() const
{
	return (_signreq);
}

int AForm::getExecReq() const
{
	return (_execreq);
}

std::string	AForm::getFormName() const
{
	return (_name);
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _signreq)
		throw LackGradeException(b, this->getFormName());
	else if (this->_issigned)
		throw SignedFormException(b, this->getFormName());
	else
		this->_issigned = 1;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low.\n";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high.\n";
}

AForm::LackGradeException::LackGradeException(Bureaucrat &b, const std::string &formName) throw()
{
	msg = b.getName() + " couldn't sign " + formName + " because they lack the required grade.\n";
}

const char* AForm::LackGradeException::what() const throw()
{
	return msg.c_str();
}

AForm::SignedFormException::SignedFormException(Bureaucrat &b, const std::string &formName) throw()
{
	msg = b.getName() + " couldn't sign " + formName + " because it is already signed.\n";
}

const char* AForm::SignedFormException::what() const throw()
{
	return msg.c_str();
}

AForm::UnsignedFormException::UnsignedFormException(const Bureaucrat &b, const std::string &formName) throw()
{
	(void) b;
	msg = formName + " must be signed before it is executed.\n";
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return msg.c_str();
}

void	AForm::print(std::ostream& os) const
{	
	if (_issigned == 1)
		os << "Signed ";
	else
		os << "Unsigned ";
	os << "Aform \"" << _name << "\" requires grade " << _signreq;
	os << " to sign and grade " << _execreq << " to execute.";

}
std::ostream& operator<<(std::ostream &os, const AForm &f)
{
	f.print(os);
	return (os);
}
