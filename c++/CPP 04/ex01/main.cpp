/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:08:27 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/01 19:41:39 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	j->makeSound(); // This should output: Woof!
	i->makeSound(); // This should output: Miau!
	std::cout << std::endl;

	const Animal *meta[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; i++)
	{
		delete meta[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	Dog *dog = new Dog();
	dog->setIdea(0, "I am a dog");
	Dog *dogclone = new Dog(*dog);
	dog->setIdea(0, "Am I a dog?");
	std::cout << "dogclone: " << dogclone->getIdea(0) << std::endl;
	std::cout << "dog: " << dog->getIdea(0) << std::endl;
	std::cout << std::endl;

	delete j;
	delete i;
	delete dog;
	delete dogclone;

	return 0;
}
