/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:10:00 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/19 18:22:56 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b1("John", 1);
		std::cout << b1 << std::endl;
		Bureaucrat b2("Jane", 150);
		std::cout << b2 << std::endl;
		Bureaucrat b3("Jack", 151);
		std::cout << b3.getName() << " has a grade of " << b3.getGrade() << std::endl;
		Bureaucrat b4("Jill", 0);
		std::cout << b4.getName() << " has a grade of " << b4.getGrade() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

	try {
		Bureaucrat b4("Jill", 0);
		std::cout << b4.getName() << " has a grade of " << b4.getGrade() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

	try {
		Bureaucrat b1("John", 1);
		b1.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

	try {
		Bureaucrat b1("John", 150);
		b1.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

	return 0;
}