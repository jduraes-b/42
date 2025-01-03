/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:36:08 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/17 20:42:07 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap	Frag("FragTrap");
	std::string	target = "target";

	Frag.attack(target);
	Frag.highFivesGuys();
	return (0);
}
