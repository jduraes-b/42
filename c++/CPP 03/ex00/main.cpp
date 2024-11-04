/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:13:43 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/17 19:22:33 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

int main()
{
	ClapTrap claptrap("Claptrap");
	std::string enemy = "enemy";

	claptrap.attack(enemy);
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);
	for (int i = 0; i < 12; i++)
	{
		if (i % 2 == 0)
			claptrap.attack(enemy);
		else
			claptrap.beRepaired(5);
	}
	return (0);
}