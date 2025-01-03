/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:39:13 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/25 20:07:39 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hitpoints = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->guard = 0;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->name = name;
	this->hitpoints = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->guard = 0;
}

ScavTrap::ScavTrap(const ScavTrap	&copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->name = copy.name;
	this->hitpoints = copy.hitpoints;
	this->energy_points = copy.energy_points;
	this->attack_damage = copy.attack_damage;
	this->guard = copy.guard;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->name = src.name;
	this->hitpoints = src.hitpoints;
	this->energy_points = src.energy_points;
	this->attack_damage = src.attack_damage;
	this->guard = src.guard;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(std::string& target)
{
	if (this->hitpoints > 0 && this->energy_points > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points--;
	}
	else if (this->hitpoints <= 0)
		std::cout << "ScavTrap " << this->name << " is dead and cannot attack" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is out of energy and cannot attack" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->guard == 0)
	{
		std::cout << "ScavTrap " << this->name << " has entered in gate keeper mode" << std::endl;
		this->guard = 1;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " has exited gate keeper mode" << std::endl;
		this->guard = 0;
	}
}
