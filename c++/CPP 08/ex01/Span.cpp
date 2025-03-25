/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:51:41 by jduraes-          #+#    #+#             */
/*   Updated: 2025/03/12 20:30:31 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
}

Span& Span::operator=(const Span &other)
{
	if (_N != other._N)
		_N = other._N;
	return *this;
}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span()
{
}

void	Span::addNumber(unsigned int N)
{
	
}