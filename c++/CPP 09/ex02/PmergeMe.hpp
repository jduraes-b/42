/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:45:54 by jduraes-          #+#    #+#             */
/*   Updated: 2025/05/06 19:11:19 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
// vector, deque
#include <iostream>
#include <string>
#include <vector>
#include <deque>

class	PmergeMe
{
	private:
		std::vector<int>	_v;
		std::deque<int>	_d;
		int	_size;
	public:
		PemergeMe(int argc, char** argv);
		~PemergeMe();
		mergeSort();
		
};

# endif
