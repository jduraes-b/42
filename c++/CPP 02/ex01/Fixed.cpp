/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:11:02 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/23 18:43:51 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = static_cast<int>(roundf(value * (1 << fractional_bits)));
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = value * (1 << fractional_bits);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed & Fixed::operator = (const Fixed &other)
{
	std::cout << "Assignment operator called" << std::endl;
	this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << fractional_bits));
}

int		Fixed::toInt(void) const
{
	return (this->value >> fractional_bits);
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw_bits)
{
	this->value = raw_bits;
}

std::ostream	&operator<<(std::ostream &o, const Fixed &value)
{
	o << value.toFloat();
	return (o);
}
