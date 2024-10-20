/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:55:30 by jduraes-          #+#    #+#             */
/*   Updated: 2024/10/20 21:41:07 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	std::cout << "Phonebook created!" << std::endl;
	this->tindex = 0;
}

Phonebook::~Phonebook()
{
	std::cout << "Phonebook destroyed!" << std::endl;
}

void	Phonebook::update_index()
{
	int i = 0;
	while (i < 7)
	{
		this->contacts[i] = this->contacts[i+1];
		this->contacts[i].set_index(i + 1);
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

std::string	Phonebook::format(std::string src)
{
	if (src.length() >= 10)
	{
		src.erase(src.begin() + 9, src.end());
		src.append(".");
	}
	return (src);
}

void	Phonebook::search()
{
	int i = 0;
	std::string input;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (i < this->tindex)
	{
		std::cout << std::setw(10) << this->contacts[i].get_index() << "|";
		std::cout << std::setw(10) << format(this->contacts[i].get_fname()) << "|";
		std::cout << std::setw(10) << format(this->contacts[i].get_lname()) << "|";
		std::cout << std::setw(10) << format(this->contacts[i].get_nick()) << std::endl;
		i++;
	}
	std::cout << "Enter the index of the contact you wish to view: ";
	std::getline(std::cin, input);
	i = 0;
	while (i < this->tindex)
	{
		std::stringstream ss;
        ss << this->contacts[i].get_index();
		if (input == ss.str())
		{
			std::cout << "First name: " << this->contacts[i].get_fname() << std::endl;
			std::cout << "Last name: " << this->contacts[i].get_lname() << std::endl;
			std::cout << "Nickname: " << this->contacts[i].get_nick() << std::endl;
			std::cout << "Phone number: " << this->contacts[i].get_phonenr() << std::endl;
			std::cout << "Darkest secret: " << this->contacts[i].get_secret() << std::endl;
			break ;
		}
		i++;
	}
	if (i >= this->tindex)
	{
		std::cout << "Invalid index. Please try again." << std::endl;
	}
}