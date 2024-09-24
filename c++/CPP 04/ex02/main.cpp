/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:08:27 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/24 19:47:47 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	//const Animal *a = new Animal();
	//This should not compile because Animal is an abstract class
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	j->makeSound(); // This should output: Woof!
	i->makeSound(); // This should output: Miau!

	Dog *dog = new Dog();
	dog->setIdea(0, "I am a dog");
	Dog *dogclone = new Dog(*dog);
	dog->setIdea(0, "Am I a dog?");
	std::cout << dogclone->getIdea(0) << std::endl;
	std::cout << dog->getIdea(0) << std::endl;


	delete j;
	delete i;
	delete dog;
	delete dogclone;

	return 0;
}