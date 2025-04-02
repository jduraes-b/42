/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:15:06 by jduraes-          #+#    #+#             */
/*   Updated: 2025/04/02 20:51:14 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(): stack()
{
	std::cout<< "MutantStack default constructor called\n";
}

template <typename T>
MutantStack<T>::MutantStack(const stack& other): stack(other)
{
	std::cout<< "MutantStack copy constructor called\n";
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout<< "MutantStack destructor called\n";
}

template <typename T>
typename MutantStack<T>::stack& MutantStack<T>::operator=(const stack& other) //what
{
	if (*this != other)
		*this = other;
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->c.end();
}
