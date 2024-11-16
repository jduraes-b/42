/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:05:18 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/14 19:48:05 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class humanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		humanA(std::string name, Weapon &weapon);
		~humanA();
		void attack(void);
};

#endif
