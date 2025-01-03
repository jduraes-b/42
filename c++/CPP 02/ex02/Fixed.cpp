/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:11:02 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/23 18:46:03 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value (0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = static_cast<int>(roundf(value * (1 << fractional_bits)));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed & Fixed::operator = (const Fixed &other)
{
	std::cout << "Assignment operator called" << std::endl;
	this->value = other.value;
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

//	COMPARISON OPERATORS:

bool Fixed::operator < (const Fixed &other)	const
{
	return (this->value < other.getRawBits()); 
}

bool Fixed::operator <= (const Fixed &other) const
{
	return (this->value <= other.getRawBits());
}

bool Fixed::operator > (const Fixed &other) const
{
	return (this->value > other.getRawBits());
}

bool Fixed::operator >= (const Fixed &other) const
{
	return (this->value >= other.getRawBits());
}

bool Fixed::operator == (const Fixed &other) const
{
	if(this->value == other.getRawBits())
		return (1);
	return (0);
}

bool Fixed::operator != (const Fixed &other) const
{
	if(this->value == other.getRawBits())
		return (0);
	return (1);
}

//	ARITHMETIC OPERATORS:

Fixed Fixed::operator + (const Fixed &other) const
{
	Fixed	r;
	r.setRawBits(this->value + other.getRawBits());
	return (r);
}

Fixed Fixed::operator - (const Fixed &other) const
{
	Fixed	r;
	r.setRawBits(this->value - other.getRawBits());
	return (r);
}

Fixed Fixed::operator * (const Fixed &other) const
{
	Fixed	r;
	r.setRawBits((this->value * other.getRawBits()) >> fractional_bits);
	return (r);
}

Fixed Fixed::operator / (const Fixed &other) const
{
	Fixed	r;
	r.setRawBits((this->value << fractional_bits) / other.getRawBits());
	return (r);
}

// INCREMENT/DECREMENT OPERATORS:

Fixed & Fixed::operator ++ ()
{
    this->value += (1 /*<< fractional_bits*/);
    return *this;
}

Fixed Fixed::operator ++ (int)
{
	Fixed tmp = *this;
    this->value += (1 /*<< fractional_bits*/);
    return (tmp);
}

Fixed & Fixed::operator -- ()
{
    this->value -= (1 /*<< fractional_bits*/);
    return *this;
}

Fixed Fixed::operator -- (int)
{
	Fixed tmp = *this;
    this->value -= (1 /*<< fractional_bits*/);
    return (tmp);
}

//OVERLOADED MEMBER FUNCTIONS

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

//

std::ostream	&operator<<(std::ostream &o, const Fixed &value)
{
	o << value.toFloat();
	return (o);
}
