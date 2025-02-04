/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:25:53 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/30 19:28:43 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

Form*	Intern::makeForm(std::string name, std::string target)
{
	std::string type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (Intern::*functions[3]) (std::string) = {&Intern::createShrubbery, &Intern::robotomyRequest, &Intern::presidentialPardon};
	for (int i = 0; i < 3; i++)
	{
		if(name == type[i])
			return ((this->*functions[i])(target));
	}
	std::cout << "Unexpected form name, form names are: \"shrubbery creation\", \"robotomy request\", \"presidential pardon\"." << std::endl;
	return (NULL);
}

Form*	Intern::createShrubbery(std::string target)
{
	std::cout << "Intern creates a ShrubberyCreationForm." << std::endl;
	return (new ShrubberyCreationForm(target));
}

Form*	Intern::robotomyRequest(std::string target)
{
	std::cout << "Intern creates a RobotomyRequestForm." << std::endl;
	return (new RobotomyRequestForm(target));
}

Form*	Intern::presidentialPardon(std::string target)
{
	std::cout << "Intern creates a PresidentialPardonForm." << std::endl;
	return (new PresidentialPardonForm(target));
}
