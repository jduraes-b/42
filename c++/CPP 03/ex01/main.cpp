/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:13:43 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/17 20:18:27 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>

int main()
{
	ScavTrap Scav("ScavTrap");
	std::string target = "target";
	
	Scav.attack(target);
	Scav.guardGate();
	Scav.guardGate();
	Scav.takeDamage(10);
	Scav.beRepaired(10);
	for (int i = 0; i < 10; i++)
		Scav.attack(target);
	return (0);
}