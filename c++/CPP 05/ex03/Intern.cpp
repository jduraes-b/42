/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:25:53 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/20 20:30:29 by jduraes-         ###   ########.fr       */
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
	std::cout << "unexpected form name.\n form names are: \"shrubbery creation\", \"robotomy request\", \"presidential pardon \"" << std::endl;
	return NULL;
}

Form*	Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form*	Intern::robotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form*	Intern::presidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}
