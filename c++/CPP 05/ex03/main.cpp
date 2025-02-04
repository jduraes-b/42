/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:25:16 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/29 21:34:38 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <string>

int	main()
{
	Bureaucrat	b1("Carl", 150);
	Bureaucrat	b2("Karl", 1);

	Intern	i1;
	Form	*f1;
	Form	*f2;
	Form	*f3;

	f1 = i1.makeForm("robotomy request", "Carl");
	f2 = i1.makeForm("presidential pardon", "Carl");
	f3 = i1.makeForm("WrongForm", "Carl");

	b1.executeForm(*f1);
	b1.signForm(*f1);
	b2.executeForm(*f1);
	b2.signForm(*f1);
	b2.executeForm(*f1);

	std::cout << std::endl;
	
	b2.signForm(*f2);
	b1.executeForm(*f2);
	b2.executeForm(*f2);
	delete f1;
	delete f2;

	return 0;
}
