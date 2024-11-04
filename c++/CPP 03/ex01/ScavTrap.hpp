/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:31:09 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/17 20:16:31 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		int	guard;
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap	&copy);
		~ScavTrap();
		void	attack(std::string &target);
		void	guardGate();
		ScavTrap	&operator=(const ScavTrap &src);
};

#endif