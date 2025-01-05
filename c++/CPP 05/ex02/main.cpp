/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 19:25:16 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/05 19:40:44 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string.h>

int	main()
{
	Bureaucrat	b1("Carl", 150);
	Bureaucrat	b2("Karl", 1);

	ShrubberyCreationForm	f1("1A");

	b1.signForm(f1);
	b2.signForm(f1);
	b1.executeForm(f1);
	b2.executeForm(f1);

	return 0;
}