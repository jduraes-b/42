/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:07:24 by jduraes-          #+#    #+#             */
/*   Updated: 2025/02/24 20:12:19 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void	print(T const &t)
{
	std::cout << t << std::endl;
}

int	main(void)
{
	int		int_arr[5] = {1, 2, 3, 4, 5};
	float	float_arr[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char	char_arr[5] = {'a', 'b', 'c', 'd', 'e'};

	iter(int_arr, 5, print);
	iter(float_arr, 5, print);
	iter(char_arr, 5, print);

	return (0);
}