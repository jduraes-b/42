/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:05:01 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/24 18:52:35 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->type = other.type;
	if(this->brain)
		delete this->brain;
	this->brain = new Brain(*other.brain);
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

void	Dog::setIdea(int i, std::string idea)
{
	brain->setIdea(i, idea);
}

std::string Dog::getIdea(int i) const
{
	return (brain->getIdea(i));
}