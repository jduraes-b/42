/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:25:16 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/08 19:19:26 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

int	main()
{
	Bureaucrat	b1("Carl", 150);
	Bureaucrat	b2("Karl", 1);

	ShrubberyCreationForm	f1("../");
	RobotomyRequestForm	f2("Qarl");
	PresidentialPardonForm f3("Harl");

	b1.signForm(f1);
	b2.signForm(f1);
	b1.executeForm(f1);
	b2.executeForm(f1);
	std::cout << std::endl;
	b1.signForm(f2);
	b2.signForm(f2);
	b1.executeForm(f2);
	b2.executeForm(f2);
	std::cout << std::endl;
	b1.signForm(f3);
	b2.signForm(f3);
	b1.executeForm(f3);
	b2.executeForm(f3);

	return 0;
}
