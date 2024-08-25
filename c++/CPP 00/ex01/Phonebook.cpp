/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:55:30 by jduraes-          #+#    #+#             */
/*   Updated: 2024/08/25 20:49:46 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	std::cout << "Phonebook created!" << std::endl;
}

Phonebook::~Phonebook()
{
	std::cout << "Phonebook destroyed!" << std::endl;
}

void	Phonebook::update_index()
{
	int i = 0;
	while (i < this->tindex)
	{
		this->contacts[i] = this->contacts[i+1];
		//this->contacts[i].set_index(this->contacts[i].get_index() - 1);
		i++;
	}
}

void	Phonebook::add_contact()
{
	std::string input;
	if (this->tindex < 8)
	{
		this->tindex++;
		std::cout << "Enter the contact's first name: ";
		std::getline(std::cin, input);
		this->contacts[this->tindex - 1].set_fname(input);
		std::cout << "Enter the contact's last name: ";
		std::getline(std::cin, input);
		this->contacts[this->tindex - 1].set_lname(input);
		std::cout << "Enter the contact's nickname: ";
		std::getline(std::cin, input);
		this->contacts[this->tindex - 1].set_nick(input);
		std::cout << "Enter the contact's phone number: ";
		std::getline(std::cin, input);
		this->contacts[this->tindex - 1].set_phonenr(input);
		std::cout << "Enter the contact's darkest secret: ";
		std::getline(std::cin, input);
		this->contacts[this->tindex - 1].set_secret(input);
		this->contacts[this->tindex - 1].set_index(this->tindex);
	}
	else
	{
		std::cout << "Phonebook is full, ";
		std::cout << this->contacts[0].get_fname();
		std::cout << " will be overwritten" << std::endl;
		this->update_index();
		this->tindex--;
		Phonebook::add_contact();
	}
}