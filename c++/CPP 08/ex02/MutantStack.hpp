/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:58:49 by jduraes-          #+#    #+#             */
/*   Updated: 2025/04/02 20:42:42 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>

template <class T>
class MutantStack: public std::stack<T>
{
	public:
		typedef std::stack<T>	stack;
		typedef typename stack::container_type::iterator iterator;
		MutantStack();
		MutantStack(const stack& other);
		~MutantStack();
		stack	&operator=(const stack& other);
		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"

# endif