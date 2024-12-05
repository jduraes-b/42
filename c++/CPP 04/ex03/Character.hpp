/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:36:47 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/05 20:30:24 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string.h>

class Character : public ICharacter
{
	private:
		AMateria *inventory[4];
		std::string name;
		AMateria *bin[256];
		int	t;

	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		virtual ~Character();
		Character &operator=(const Character &other);
		std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
