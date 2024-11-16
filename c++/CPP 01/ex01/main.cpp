/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:59:59 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/14 19:28:43 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

int	main(int argc, char **argv)
{
	Zombie	*Horde;
	int		n;
	
	if (argc == 3 && argv[1])
	{
		std::stringstream ss(argv[1]);
		ss >> n;
		if (ss.fail() || n < 0 || n > 1000)
		{
			std::cout << "Wrong number of zombies. Available 1 to 1000 zombie range" << std::endl;
			return (1);
		}
		Horde = zombieHorde(n, argv[2]);
		for (int i = 0; i < n; i++)
			Horde[i].announce();
		delete[] Horde;
		return (0);
	}
	std::cout << "Usage: ./moarBrainz <number_of_zombies> <zombie_name>" << std::endl;
	return (1);
}
