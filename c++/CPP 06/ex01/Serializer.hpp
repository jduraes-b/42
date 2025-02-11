/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:26:07 by jduraes-          #+#    #+#             */
/*   Updated: 2025/02/10 20:06:32 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	int 		n;
	std::string	s;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &other);
		Serializer &operator=(Serializer const &other);
	public:
		~Serializer();
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

# endif
