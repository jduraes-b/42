/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:51:37 by jduraes-          #+#    #+#             */
/*   Updated: 2025/02/26 20:47:26 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <exception>

template<typename T>
Array<T>::Array()
{
	std::cout << "Array default constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	_e = new T[n];
	_l = n;
	std::cout << "Array sized constructor called" << std::endl;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	std::cout << "Array assignment operator called" << std::endl;
	if (this == other)
		return *this;
	delete[] _e;
	_e = new T[other._l];
	_l = other._l;
	return *this;
}

template<typename T>
Array<T>::Array(const Array &other)
{
	std::cout << "Array copy constructor called" << std::endl;
	if (this == other)
		return ;
	this = other;
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Array desructor called" << std::endl;
	if (_l)
		delete[] _e;
}

template<typename T>
size_t	Array<T>::size()
{
	return _l;
}

template<typename T>
T& Array<T>::operator[](size_t i)
{
	if (i <= _l)
		return _e[i];
	throw OutOfBoundsException();
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index is out of bounds.\n";
}
