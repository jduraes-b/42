/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:28:31 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/14 19:48:09 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class humanB
{
	private:
		std::string name;
		Weapon *weapon;

	public:
		humanB(std::string name);
		~humanB();
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif
