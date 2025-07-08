/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:58:19 by jduraes-          #+#    #+#             */
/*   Updated: 2025/07/08 19:46:20 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cctype>
#include <set>

bool easyParser(int argc, char** argv)
{	
	if (argc < 3 || argc > 5000) {
		std::cout<<"Error: accepted argument count ranges from 2 to 3000.\n"; 
		return false;
	}
    std::set<int> seen;
	for (int i = 1; i < argc; ++i)
    {
        char* arg = argv[i];	
        for (int j = 0; arg[j] != '\0'; ++j)
        {
            if (j == 0 && arg[j] == '-')
            {
                std::cout << "Error: negative values are not allowed.\n";
                return false;
            }
            if (!std::isdigit(arg[j]))
            {
                std::cout << "Error: non-numeric value detected.\n";
                return false;
            }
        }
		int v = std::atoi(arg);        	
		if (!seen.insert(v).second) // Second returns false if v is in set
		{
           	std::cout << "Error: duplicate value.\n";
           	return false;
        }
    }
    return true;
}

int	main(int argc, char** argv)
{
	if (!easyParser(argc, argv))
		return 1;
	PmergeMe pmerge(argc, argv);
	pmerge.mergeInsertSort();
}