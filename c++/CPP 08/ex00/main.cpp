/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:14:54 by jduraes-          #+#    #+#             */
/*   Updated: 2025/03/11 19:24:41 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <set>
#include "easyfind.hpp"

int	main(void)
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::set<int> set;
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(4);
    set.insert(5);

	try {
		std::vector<int>::iterator i1 = easyfind(vec, 3);
		std::cout << "Found: " << *i1 << std::endl;
	}
	catch (const std::string& e){
		std::cout << e << std::endl;
	}
	
	try {
		std::set<int>::iterator i1 = easyfind(set, 3);
		std::cout << "Found: " << *i1 << std::endl;
	}
	catch (const std::string& e){
		std::cout << e << std::endl;
	}
	
	try {
		std::vector<int>::iterator i1 = easyfind(vec, 6);
		std::cout << "Found: " << *i1 << std::endl;
	}
	catch (const std::string& e){
		std::cout << e << std::endl;
	}
	
	try {
		std::set<int>::iterator i1 = easyfind(set, 6);
		std::cout << "Found: " << *i1 << std::endl;
	}
	catch (const std::string& e){
		std::cout << e << std::endl;
	}

	return 0;
}