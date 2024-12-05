/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:48:38 by jduraes-          #+#    #+#             */
/*   Updated: 2024/10/15 19:05:06 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) 
{
}


std::string const & AMateria::getType() const
{
	return (type);
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

AMateria::~AMateria()
{
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
