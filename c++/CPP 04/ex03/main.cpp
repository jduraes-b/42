/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 19:53:52 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/06 18:49:59 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
/*class Ice;
class Cure;*/

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	std::cout << "other tests: " <<std::endl;

	ICharacter*	Bill = new Character("Bill");
	IMateriaSource *src2 = new MateriaSource();

	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	tmp = src2->createMateria("ice");
	Bill->equip(tmp);
	tmp = src2->createMateria("cure");
	Bill->equip(tmp);
	tmp = src2->createMateria("ice");
	Bill->equip(tmp);
	tmp = src2->createMateria("cure");
	Bill->equip(tmp);
	tmp = src2->createMateria("ice");
	Bill->equip(tmp);
	Bill->unequip(3);
	Bill->use(3, *Bill);
	Bill->use(4, *Bill);

	delete src2;
	delete Bill;
	
	return 0;
}