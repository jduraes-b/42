/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:08:27 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/19 19:36:36 by jduraes-         ###   ########.fr       */
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
	
	const WrongAnimal *a = new WrongCat();
	const WrongAnimal *b = new WrongAnimal();


	j->makeSound(); // This should output: Woof!
	i->makeSound(); // This should output: Miau!
	meta->makeSound(); // This should output: Generic sound!

	a->makeSound(); // This should output: Wrong Animal sound!
	b->makeSound(); // This should output: Wrong Animal sound!


	delete meta;
	delete j;
	delete i;

	return 0;
}