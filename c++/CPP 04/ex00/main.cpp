/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:08:27 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/01 19:32:48 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	j->makeSound(); // This should output: Woof!
	i->makeSound(); // This should output: Miau!
	meta->makeSound(); // This should output: Generic sound!
	
	const WrongAnimal *b = new WrongAnimal();
	const WrongAnimal *a = new WrongCat();
	
	b->makeSound(); // This should output: Wrong Animal sound!
	a->makeSound(); // This should output: Wrong Animal sound!
	

	delete meta;
	delete j;
	delete i;
	delete a;
	delete b;
	return 0;
}
