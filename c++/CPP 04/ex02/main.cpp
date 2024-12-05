/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:08:27 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/01 19:52:26 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	//const AAnimal *a = new AAnimal();
	//This should not compile because AAnimal is an abstract class
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();

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
