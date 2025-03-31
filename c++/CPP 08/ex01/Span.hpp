/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:37:46 by jduraes-          #+#    #+#             */
/*   Updated: 2025/03/31 20:22:08 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>

class Span
{
	private:
		unsigned int	_N;
		std::vector<int>	_arr;
		
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);
		~Span();
		void	addNumber(int newn);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void	fillSpan();
};

#endif
