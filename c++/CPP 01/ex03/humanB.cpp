/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:28:14 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/14 19:47:45 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanB.hpp"

humanB::humanB(std::string name) : name(name)
{
	this->weapon = NULL;
}

humanB::~humanB()
{
}

void humanB::attack()
{
	if (this->weapon == NULL)
	{
		std::cout << this->name << " has no weapon to attack with" << std::endl;
		return ;
	}
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void humanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
