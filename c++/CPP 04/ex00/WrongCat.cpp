/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:07:21 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/30 19:06:39 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
}

void WrongCat::makeSound() const
{
	std::cout << "WrongMiau!" << std::endl;
}
