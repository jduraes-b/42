/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:25:16 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/28 20:58:38 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string.h>

int	main()
{
	Bureaucrat	b1("Carl", 150);
	Bureaucrat	b2("Karl", 1);

	std::cout << b1 << "\n" << b2 << std::endl;

	try{
		Bureaucrat b3("Qarl", 0);
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

	Form	f1("Expense Report", 1, 1);
	Form	f2("Tax Declaration", 150, 150);
	std::cout << f1 << "\n" << f2 << std::endl;
	
	try{
		Form f3("Invalid Form", 0, 0);
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}
	
	try{
		Form f4("Invalid Form", 151, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

	b1.signForm(f1);
	b1.signForm(f2);
	b2.signForm(f1);
	b2.signForm(f1);

	std::cout << f1 << "\n" << f2 << std::endl;

	return 0;
}