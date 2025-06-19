/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PemergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:56:46 by jduraes-          #+#    #+#             */
/*   Updated: 2025/06/19 19:41:43 by jduraes-         ###   ########.fr       */
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

// Helper: Generate Jacobsthal sequence up to n
std::vector<size_t> jacobsthal_sequence(size_t n) 
{
    std::vector<size_t> seq;
    if (n == 0)
        return seq;
    seq.push_back(1); // J(1)
    size_t j0 = 0, j1 = 1;
    size_t next = j1 + 2 * j0;
    while (next < n) {
        seq.push_back(next);
        j0 = j1;
        j1 = next;
        next = j1 + 2 * j0;
    }
    return seq;
}

void ford_johnson_sort(std::vector<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;

    // Pair up and split
    std::vector<int> smalls, larges;
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (arr[i] < arr[i+1]) {
            smalls.push_back(arr[i]);
            larges.push_back(arr[i+1]);
        } else {
            smalls.push_back(arr[i+1]);
            larges.push_back(arr[i]);
        }
    }
    int straggler = -1;
    bool has_straggler = (n % 2 != 0);
    if (has_straggler) straggler = arr[n-1];

    // Recursively sort larges
    ford_johnson_sort(larges);

    // Insert smalls into larges using Jacobsthal order
    std::vector<size_t> jac_seq = jacobsthal_sequence(smalls.size());
    std::vector<int> result = larges;
	for (std::vector<size_t>::iterator it = jac_seq.begin(); it != jac_seq.end(); ++it)
	{
		size_t idx = *it;
        if (idx < smalls.size())
		{
            auto pos = std::lower_bound(result.begin(), result.end(), smalls[idx]);
            result.insert(pos, smalls[idx]);
        }
    }
    // Insert any remaining smalls not covered by Jacobsthal sequence
    for (size_t i = 0; i < smalls.size(); ++i)
	{
        if (std::find(jac_seq.begin(), jac_seq.end(), i) == jac_seq.end())
		{
            auto pos = std::lower_bound(result.begin(), result.end(), smalls[i]);
            result.insert(pos, smalls[i]);
        }
    }

    // Insert straggler if present
    if (has_straggler) {
        auto pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }

    arr = result;
}

PmergeMe::mergeSort()
{
	clock_t vstart = clock();
	ford_johnson_sort(_v);
	double vtime = static_cast<double>(end - vstart) / CLOCKS_PER_SEC;

	clock_t dstart = clock();

	double dtime = static_cast<double>(end - dstart) / CLOCKS_PER_SEC;
}
