/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:06:44 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/11 19:23:57 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	private:
		AForm*	Intern::CreateShrubbery(std::string target);
		AForm*	Intern::RobotomyRequest(std::string target);
		AForm*	Intern::PresidentialPardon(std::string target);

	public:
		Intern::Intern();
		Intern::Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		Intern::~Intern();
		AForm*	Intern::makeForm(std::string name, std::string target);
};

# endif
