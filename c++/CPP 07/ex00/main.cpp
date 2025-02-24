/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:26:55 by jduraes-          #+#    #+#             */
/*   Updated: 2025/02/24 19:51:57 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main(void)
{
	std::string s[] = {"test", "another test"};
	std::string s2[] = {"arbitrary", "string"};

	std::cout << ::min(s[0], s[1]) << std::endl; // ::min is used to specify the global scope. This is because the function min is overloaded in the std namespace. It looks horrible and makes no sense.
	std::cout << ::min(s2[0], s2[1]) << std::endl;
	std::cout << min(1, 2) << std::endl;
	std::cout << min(1.0, 2.0) << std::endl;
	std::cout << ::max(s[0], s[1]) << std::endl;
	std::cout << max(1, 2) << std::endl;
	std::cout << max(1.0, 2.0) << std::endl;

	int a = 0, b = 2;
	std::cout << "Before: a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "After: a = " << a << ", b = " << b << std::endl;
	
	std::string c = "egg", d = "chicken";
	std::cout << "Before: c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "After: c = " << c << ", d = " << d << std::endl;
	
	char e = 'a', f = 'b';
	std::cout << "Before: e = " << e << ", f = " << f << std::endl;
	swap(e, f);
	std::cout << "After: e = " << e << ", f = " << f << std::endl;

	return 0;
}