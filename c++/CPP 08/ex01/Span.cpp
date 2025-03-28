/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:51:41 by jduraes-          #+#    #+#             */
/*   Updated: 2025/03/28 19:51:56 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

Span::Span(unsigned int N) : _N(N)
{
	_arr.reserve(N);
}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _N = other._N;
        _arr = other._arr;
	}
	return *this;
}

Span::Span(const Span &other): _N(other._N), _arr(other._arr)
{
}

Span::~Span()
{
	/*std::vector<int>::iterator	itt = _arr.end();
	for(std::vector<int>::iterator	it = _arr.begin(); it != itt; ++it)
	{
		delete *it;
		it = _arr.erase(it);
	}*/
}

void	Span::addNumber(int newn)
{
	if (_arr.size() == _N)
		throw std::runtime_error("Full Span.\n");
	std::vector<int>::iterator	itt = _arr.end();
	for(std::vector<int>::iterator	it = _arr.begin(); it != itt; ++it)
	{
		if (*it == newn)
			throw std::runtime_error("Number already in Span.\n");
	}
	_arr.push_back(newn);
}

static size_t abs(int n)
{
    return (n < 0) ? -n : n;
}

unsigned int	Span::shortestSpan()
{
	if (_arr.size() <= 1)
		throw std::runtime_error("No span to be found.\n");
	
	size_t	sp = UINT_MAX;
	std::vector<int>::iterator	ite = _arr.end();
	std::vector<int>::iterator	it1 = _arr.begin();
	std::vector<int>::iterator	it2;
	while (it1 != ite)
	{
		it2 = it1;
		while(++it2 != ite)
			sp = (::abs((*it1) - (*it2)) < sp) ? ::abs((*it1) - (*it2)) : sp;
		++it1;
	}
	return sp;
}

unsigned int	Span::longestSpan()
{
	if (_arr.size() <= 1)
		throw std::runtime_error("No span to be found.\n");
	
	size_t	sp = 0;
	std::vector<int>::iterator	ite = _arr.end();
	std::vector<int>::iterator	it1 = _arr.begin();
	std::vector<int>::iterator	it2;
	while (it1 != ite)
	{
		it2 = it1;
		while(++it2 != ite)
			sp = (::abs((*it1) - (*it2)) > sp) ? ::abs((*it1) - (*it2)) : sp;
		++it1;
	}
	return sp;
}
