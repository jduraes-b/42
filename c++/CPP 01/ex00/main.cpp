/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:21:48 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/14 18:56:36 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(int argc, char **argv)
{
	Zombie	*zombie;

	if (argc != 2)
	{
		std::cout << "Usage: ./BraiiiiiiinnnzzzZ <zombie_name>" << std::endl;
		return (1);
	}
	zombie = new Zombie(argv[1]);
	zombie->announce();
	delete zombie;
	randomChump("randomChump");		//stack
	zombie = newZombie("newZombie");  //heap
	zombie->announce();
	delete zombie;
	return (0);
}
