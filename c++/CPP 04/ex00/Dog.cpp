/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:05:01 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/19 19:23:08 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
}

Dog::Dog(const Dog &other) : Animal(other)
{
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

Dog::~Dog()
{
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
