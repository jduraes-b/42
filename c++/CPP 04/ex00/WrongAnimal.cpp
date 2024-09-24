/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:56:10 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/19 19:35:57 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
