/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:03:22 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/17 19:38:08 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = name;
	this->hitpoints = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap	&copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->name = copy.name;
	this->hitpoints = copy.hitpoints;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->name = src.name;
	this->hitpoints = src.hitpoints;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(std::string& target)
{
	if (this->hitpoints > 0 && this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points--;
	}
	else if (this->hitpoints <= 0)
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is out of energy and cannot attack" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitpoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
		this->hitpoints -= amount;
	}
	else
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitpoints > 0 && this->energy_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points of health!" << std::endl;
		this->hitpoints += amount;
		this->energy_points--;
	}
	else if (this->hitpoints <= 0)
		std::cout << "ClapTrap " << this->name << " is already dead" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is out of energy and cannot be repaired" << std::endl;
}
