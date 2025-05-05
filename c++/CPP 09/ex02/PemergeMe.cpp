/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PemergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:56:46 by jduraes-          #+#    #+#             */
/*   Updated: 2025/05/05 20:07:52 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PemergeMe.hpp"

PemergeMe::PemergeMe(int argc, char** argv): _size(argc - 1)
{
	for (int i = 1; i < argc; ++i)
    {
        char* arg = argv[i];
        for (int j = 0; arg[j] != '\0'; ++j)
        {
			int value = std::atoi(arg);
			_v.push_back(value);
			_d.push_back(value);
        }
    }
}