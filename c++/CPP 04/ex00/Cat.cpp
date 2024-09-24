/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:07:21 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/19 19:23:37 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
}

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

Cat::~Cat()
{
}

void Cat::makeSound() const
{
	std::cout << "Miau!" << std::endl;
}