/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:00:39 by jduraes-          #+#    #+#             */
/*   Updated: 2025/02/10 20:06:28 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data		data;
	data.n = 42;
	data.s = "example";

	uintptr_t	raw;
	raw = Serializer::serialize(&data);
	std::cout << "Serialized data: " << raw << std::endl;

	Data		*ptr;
	ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized data: " << ptr->n << " " << ptr->s << std::endl;

	return (0);
}