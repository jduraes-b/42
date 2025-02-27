/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:48:15 by jduraes-          #+#    #+#             */
/*   Updated: 2025/02/27 17:38:47 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int>	A(5);
	Array<char>	C(4);

	for (int i = 0; i < 5; i++){
		A[i] = i;
	}
	for (int i = 0; i < 4; i++){
		C[i] = i + 97;
	}
	std::cout << "Int Array size: " << A.size() << std::endl;
	std::cout << "Char Array size: " <<  C.size() << std::endl;
	for (int i = 0; i < 5; i++){
		std::cout << A[i] << std::endl;
	}
	for (int i = 0; i < 4; i++){
		std::cout << C[i] << std::endl;
	}

	try {
		std::cout << C[5] << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what();
	}

	Array<char> D(C);
	std::cout << D[3] << std::endl;
	
	return 0;
}