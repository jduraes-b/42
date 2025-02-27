/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:13:12 by jduraes-          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:48 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{ 
	private:
		T	*_e;
		size_t	_l;
	
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array& operator=(const Array &other);
		~Array();
		size_t	size();
		T& operator[](size_t i);
		const T& operator[](size_t i) const;

	class OutOfBoundsException : public std::exception {
		public:
			const char* what() const throw();
	};
};
#include "Array.tpp"
# endif
