/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PemergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:56:46 by jduraes-          #+#    #+#             */
/*   Updated: 2025/05/10 15:41:45 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PemergeMe.hpp"
#include <cstdlib>
#include <ctime>

PemergeMe::PemergeMe(int argc, char** argv) : _size(argc - 1)
{
    for (int i = 1; i < argc; ++i)
    {
        int value = std::atoi(argv[i]);
        _v.push_back(value);
        _d.push_back(value);
    }
}

void	vectorsort()
{

}

PmergeMe::mergeSort()
{
	clock_t vstart = clock();
	vectorsort();
	double vtime = static_cast<double>(end - vstart) / CLOCKS_PER_SEC;

	clock_t dstart = clock();

	double dtime = static_cast<double>(end - dstart) / CLOCKS_PER_SEC;
}
