/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:32:16 by jduraes-          #+#    #+#             */
/*   Updated: 2025/03/31 21:14:12 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try{
		sp.addNumber(11);
	}
	catch(const std::exception &e){std::cerr<<e.what();}
	
	Span bsp = Span(10000);
	bsp.fillSpan();
	std::cout << bsp.shortestSpan() << std::endl;
	std::cout << bsp.longestSpan() << std::endl;
	try{
		bsp.fillSpan();
	}
	catch(const std::exception &e){std::cerr<<e.what();}

	int	arr[] = {4, 20, 5, 12, 30, 1, 33, 100, 42, 71};
	std::vector<int>	v;
	v.assign(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Span nsp = Span(10);
	nsp.addNumbers(v.begin(), v.end());
	std::cout << nsp.shortestSpan() << std::endl;
	std::cout << nsp.longestSpan() << std::endl;
	try{
		nsp.addNumbers(v.begin(), v.end());
	}
	catch(const std::exception &e){std::cerr<<e.what();}
	return 0;
}