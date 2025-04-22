/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:14:40 by jduraes-          #+#    #+#             */
/*   Updated: 2025/04/22 21:42:02 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstring>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error\n";
		return 1;
	}
	RPN	rpn;
	try {
		rpn.solve(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error\n";
		return 1;
	}
	std::cout << rpn.result() << std::endl;
	return 0;
}