/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:45:54 by jduraes-          #+#    #+#             */
/*   Updated: 2025/07/03 16:29:36 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
// vector, deque
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

class	PmergeMe
{
	private:
		std::vector<size_t>	_v;
		std::deque<size_t>	_d;
		size_t	_size;
	public:
		PmergeMe(int argc, char** argv);
		~PmergeMe();
		void	ford_johnson_sort(std::vector<size_t>& arr);
		void	mergeInsertSort();
		
};

# endif
