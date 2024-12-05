/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:39:14 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/05 20:31:40 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() 
{
}

Character::~Character() 
{
	for (int i = 0; inventory[i] != NULL && i < 5; i++)
		delete inventory[i];
	for (int i = 0; this->bin[i] != NULL && i < 257; i++)
		delete bin[i];
}

Character::Character(std::string name) : name(name), t(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 256; i++)
		bin[i] = NULL;
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
	return (*this);
}

const std::string & Character::getName() const
{
	return (this->name);
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
	bin[t++] = m;
	std::cout << "No inventory slot available to equip" << std::endl;
}

static void	inv_sort(AMateria **inventory, int idx)
{
	int i = idx - 1;
	while (++i < 3)
	{
		if (inventory[i + 1])
			inventory[i] = inventory[i+1];
	}
	inventory[i] = NULL;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3){
		std::cout << "invalid id" << std::endl;
		return ;
	}
	if (inventory[idx] != NULL)
		bin[t++] = inventory[idx];
	inv_sort(inventory, idx);
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > -1 && idx < 5 && inventory[idx] != NULL)
		inventory[idx]->use(target);
}
