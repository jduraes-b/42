/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:53:21 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/23 19:00:27 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main( void ) {
	
	Fixed			a;
	Fixed const		b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << "\n";
	std::cout << "other:" << std::endl;
	Fixed	c(10);
	Fixed	d(5);
	std::cout << --c << std::endl;
	std::cout << c-- << std::endl;
	std::cout << c++ << std::endl;
	std::cout << ++c << std::endl; //10
	std::cout << c + d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c / d << std::endl;
	std::cout << c * d << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
	return 0;
}
