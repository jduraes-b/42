/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:56:10 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/01 19:49:11 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->type = "AAnimal";
}

AAnimal::AAnimal(std::string type)
{
	this->type = type;
}

AAnimal::AAnimal(const AAnimal &other)
{
	*this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal()
{
}

std::string AAnimal::getType() const
{
	return (this->type);
}
