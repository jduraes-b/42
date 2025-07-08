/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:56:46 by jduraes-          #+#    #+#             */
/*   Updated: 2025/06/25 19:44:35 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <vector>
#include <ctime>

PmergeMe::PmergeMe(int argc, char** argv) : _size(argc - 1)
{
    for (int i = 1; i < argc; ++i)
    {
        size_t value = std::atoi(argv[i]);
        _v.push_back(value);
        _d.push_back(value);
    }
}

PmergeMe::~PmergeMe() 
{
    // No manual cleanup needed
}

//Generate Jacobsthal sequence up to n
std::vector<size_t> jacobsthal_sequence(size_t n) 
{
    std::vector<size_t> seq;
    size_t j0 = 1, j1 = 1;
    while (j1 < n) {
        seq.push_back(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
    return seq;
}

/*void PmergeMe::ford_johnson_sort(std::vector<size_t>& arr)
{
    size_t n = arr.size();
    if (n <= 1) return;

    // Split into smalls and larges
    std::vector<size_t> smalls, larges;
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (arr[i] < arr[i+1]) {
            smalls.push_back(arr[i]);
            larges.push_back(arr[i+1]);
        } else {
            smalls.push_back(arr[i+1]);
            larges.push_back(arr[i]);
        }
    }
	// Check for odd size array and save the straggler
	size_t straggler = (n % 2 != 0) ? arr[n-1] : 0;
    // Recursively sort the larger group
    ford_johnson_sort(larges);
    // Prepare Jacobsthal insertion order
    std::vector<size_t> jac_seq = jacobsthal_sequence(smalls.size());
    // Merge back: start from sorted larges
    std::vector<size_t> result = larges;
    std::vector<bool> inserted(smalls.size(), false);
    // First insert smalls in Jacobsthal order
    for (size_t j = 0; j < jac_seq.size(); ++j) {
        size_t idx = jac_seq[j];
        if (!inserted[idx]) {
            std::vector<size_t>::iterator pos = std::lower_bound(result.begin(), result.end(), smalls[idx]);
            result.insert(pos, smalls[idx]);
            inserted[idx] = true;
        }
    }
    // Insert any remaining smalls
    for (size_t i = 0; i < smalls.size(); ++i) {
        if (!inserted[i]) {
            std::vector<size_t>::iterator pos = std::lower_bound(result.begin(), result.end(), smalls[i]);
            result.insert(pos, smalls[i]);
        }
    }
    // Insert straggler if present
    if (has_straggler) {
        std::vector<size_t>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
    arr = result;
}*/

void	PmergeMe::mergeInsertSort()
{
	std::cout << "Before: ";
	printContainer(_v);
	clock_t vstart = clock();
	ford_johnson_sort(_v);
	clock_t vend = clock();
	std::cout << "After: ";
	printContainer(_v);
	double vtime = static_cast<double>(vend - vstart) * 1e6 / CLOCKS_PER_SEC;
	std::cout << "Vector sort time: " << vtime << " us\n";
	clock_t dstart = clock();
	ford_johnson_sort(_d);
	clock_t dend = clock();
	double dtime = static_cast<double>(dend - dstart) * 1e6 / CLOCKS_PER_SEC;
	std::cout << "Deque sort time: " << dtime << " us\n";
}
