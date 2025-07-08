/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:45:54 by jduraes-          #+#    #+#             */
/*   Updated: 2025/07/08 18:32:17 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

std::vector<size_t> jacobsthal_sequence(size_t n);

class	PmergeMe
{
	private:
		std::vector<size_t>	_v;
		std::deque<size_t>	_d;
		size_t	_size;
	public:
		PmergeMe(int argc, char** argv);
		~PmergeMe();
		template<typename Container>
		void	ford_johnson_sort(Container& arr);
		template<typename Container>
		void	printContainer(Container& arr);
		void	mergeInsertSort();
		
};

// Template Implementations:
template<typename Container>
void PmergeMe::ford_johnson_sort(Container& arr)
{
	typedef typename Container::value_type T;
    size_t n = arr.size();
    if (n <= 1) return;

    // Split into smalls and larges
    Container smalls, larges;
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
    bool has_straggler = (n % 2 != 0);
    T straggler = has_straggler ? arr[n-1] : T();
    // Recursively sort the larger group
    ford_johnson_sort(larges);
    // Prepare Jacobsthal insertion order
    std::vector<size_t> jac_seq = jacobsthal_sequence(smalls.size());
    // Merge back: start from sorted larges
    Container result = larges;
    std::vector<bool> inserted(smalls.size(), false);
    // First insert smalls in Jacobsthal order
    for (size_t j = 0; j < jac_seq.size(); ++j) {
        size_t idx = jac_seq[j];
        if (!inserted[idx]) {
            typename Container::iterator pos = std::lower_bound(result.begin(), result.end(), smalls[idx]);
            result.insert(pos, smalls[idx]);
            inserted[idx] = true;
        }
    }
    // Insert any remaining smalls
    for (size_t i = 0; i < smalls.size(); ++i) {
        if (!inserted[i]) {
            typename Container::iterator pos = std::lower_bound(result.begin(), result.end(), smalls[i]);
            result.insert(pos, smalls[i]);
        }
    }
    // Insert straggler if present
    if (straggler) {
        typename Container::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
    arr = result;
}

template<typename Container>
void	PmergeMe::printContainer(Container& arr)
{
    // Container::const_iterator is a nested type—must prefix with 'typename'
    for (typename Container::const_iterator it = arr.begin(); it != arr.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
}

# endif
