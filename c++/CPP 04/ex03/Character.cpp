/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:39:14 by jduraes-          #+#    #+#             */
/*   Updated: 2024/10/16 20:03:15 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <string.h>

Character::Character() 
{
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

Character::Character(std::string name) : name(name) 
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other) 
{
	*this = other;
}

Character &Character:: operator=(const Character &other)
{
	name = other.name; 
	for (int i = 0; i < 4; i++)
	{
		if (other.inventory[i])
		{
			delete inventory[i];
			inventory[i] = other.inventory[i]->clone();
		}
		else
			inventory[i] = NULL;
	}
}

void	Character::equip(AMateria *m)
{
	int i = -1;
	while(++i < 4)
	{
		if(inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
	std::cout << "No inventory slot available to equip" << std::endl;
}

