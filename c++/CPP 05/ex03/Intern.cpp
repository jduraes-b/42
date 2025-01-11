/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:25:53 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/11 19:34:08 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
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

AForm*	Intern::makeForm(std::string name, std::string target)
{
	std::string type[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*functions[3]) (std::string) = {&Intern::createShrubbery, &Intern::robotomyRequest, &Intern::presidentialPardon};
	for (int i = 0; i < 3; i++)
	{
		if(name == type[i])
			return ((this->*functions[i])(target));
	}
	std::cout << "unexpected form name.\n form names are: \"shrubbery creation\", \"robotomy request\", \"presidential pardon \"" << std::endl;
	return (nullptr);
}

AForm*	createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	robotomyRequest(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	presidentialPardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}
