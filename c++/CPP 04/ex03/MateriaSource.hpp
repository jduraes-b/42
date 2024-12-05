/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:24:06 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/03 19:27:59 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
//#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:	
		AMateria *inventory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &other);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
