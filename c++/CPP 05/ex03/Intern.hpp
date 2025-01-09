/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:06:44 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/09 19:13:41 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	private:

	public:
		Intern::Intern();
		Intern::Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		Intern::~Intern();
		void	Intern::makeForm(std::string name, std::string target);
};

# endif
