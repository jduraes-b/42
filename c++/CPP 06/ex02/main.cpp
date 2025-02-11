/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:39:39 by jduraes-          #+#    #+#             */
/*   Updated: 2025/02/11 19:44:30 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//#include <iomanip>
//#include <limits>
//#include <cmath>
//#include <cstring>
//#include <cctype>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	int i = rand() % 3;

	if (i == 0)
	{
		std::cout << "A instance created" << std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "B instance created" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "C instance created" << std::endl;
		return new C;
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class type C" << std::endl;
	else
		std::cout << "Class type unknown" << std::endl;
}

void	identify(Base &p)
{
	std::string type[] = {"A", "B", "C", "Class type unknown"};
	int i = 0;
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
	}
	catch (std::exception &e)
	{
		i++;
		try {
			B &b = dynamic_cast<B&>(p);
			(void)b;
		}
		catch (std::exception &e)
		{
			i++;
			try {
				C &c = dynamic_cast<C&>(p);
				(void)c;
			}
			catch (std::exception &e)
			{
				i++;
			}
		}
	}
	std::cout << "Class type " << type[i] << std::endl;
}

int	main(void)
{
	srand(static_cast<unsigned int>(time(0)));
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
	return (0);
}