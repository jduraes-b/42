/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:26:20 by jduraes-          #+#    #+#             */
/*   Updated: 2024/08/26 20:21:19 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "Phonebook.hpp"

int	main()
{
	Phonebook	phonebook;
	std::string	str;

	while (1)
	{
		std::cout << "Please enter a command: ";
		std::getline(std::cin, str);
		if (str == "ADD")
		{
			phonebook.add_contact();
		}
		else if (str == "SEARCH")
		{
			phonebook.search();
		}
		else if (str == "EXIT")
		{
			std::cout << "Exiting program..." << std::endl;
			break ;
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
		}
	}
}