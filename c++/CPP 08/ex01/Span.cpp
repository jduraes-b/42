/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:51:41 by jduraes-          #+#    #+#             */
/*   Updated: 2025/04/03 19:01:23 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <ctime>
#include <cstdlib>
#include <algorithm>

Span::Span(unsigned int N) : _N(N)
{
	std::cout<<"Span constructor called\n";
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
		throw std::runtime_error("Span is full.\n");
	std::vector<int>::iterator	itt = _arr.end();
	for(std::vector<int>::iterator	it = _arr.begin(); it != itt; ++it)
	{
		if (*it == newn)
			throw std::runtime_error("Number already in Span.\n");
	}
	_arr.push_back(newn);
}

static size_t tabs(int n)
{
    return n < 0 ? -n : n;
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
			sp = (::tabs((*it1) - (*it2)) < sp) ? ::tabs((*it1) - (*it2)) : sp;
		++it1;
	}
	return sp;
}

unsigned int	Span::longestSpan()
{
	if (_arr.size() <= 1)
		throw std::runtime_error("No span to be found.\n");
	int min = *std::min_element(_arr.begin(), _arr.end());
	int max = *std::max_element(_arr.begin(), _arr.end());
	return max - min;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::cout<<"Span iterator range filler called\n";
    if (_arr.size() + std::distance(begin, end) > _N)
        throw std::runtime_error("Adding range exceeds Span capacity.\n");

    _arr.insert(_arr.end(), begin, end);
}

void	Span::fillSpan()
{
	std::cout<<"fillSpan called\n";
    if (_arr.size() >= _N)
		throw std::runtime_error("Span is already full.\n");
	srand(static_cast<unsigned int>(time(0)));
	while (_arr.size() < _N)
		_arr.push_back(rand());
}
