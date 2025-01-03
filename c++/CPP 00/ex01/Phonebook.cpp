/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:55:30 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/09 17:50:32 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <limits>

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

void	Phonebook::clear_curr()
{
	if(!this->contacts[this->tindex].get_fname().empty())
		this->contacts[this->tindex].set_fname("");
	if(!this->contacts[this->tindex].get_lname().empty())
		this->contacts[this->tindex].set_lname("");
	if(!this->contacts[this->tindex].get_nick().empty())
		this->contacts[this->tindex].set_nick("");
	if(!this->contacts[this->tindex].get_phonenr().empty())
		this->contacts[this->tindex].set_phonenr("");
	if(!this->contacts[this->tindex].get_secret().empty())
		this->contacts[this->tindex].set_secret("");
}

bool Phonebook::getInput(const std::string& prompt, std::string& input, void (Contacts::*setter)(const std::string), Contacts& contact, int& tindex, Phonebook& phonebook) {
    std::cout << prompt;
    std::getline(std::cin, input);
    if (!input.empty() && !std::cin.eof()) {
        (contact.*setter)(input);
        return true;
    } 
	else if (std::cin.eof()) {
		std::cout << "Exiting program..." << std::endl;
		return false;
	}
	else {
        tindex--;
        phonebook.clear_curr();
		std::cout << "Invalid input." << std::endl;
        return false;
    }
}

void Phonebook::add_contact()
{
	std::string input;
	if (this->tindex < 8)
	{
		this->tindex++;
		const int currentIndex = this->tindex - 1;

		if (!getInput("Enter the contact's first name: ", input, &Contacts::set_fname, this->contacts[currentIndex], this->tindex, *this)) return;
		if (!getInput("Enter the contact's last name: ", input, &Contacts::set_lname, this->contacts[currentIndex], this->tindex, *this)) return;
		if (!getInput("Enter the contact's nickname: ", input, &Contacts::set_nick, this->contacts[currentIndex], this->tindex, *this)) return;
		if (!getInput("Enter the contact's phone number: ", input, &Contacts::set_phonenr, this->contacts[currentIndex], this->tindex, *this)) return;
		if (!getInput("Enter the contact's darkest secret: ", input, &Contacts::set_secret, this->contacts[currentIndex], this->tindex, *this)) return;

		this->contacts[currentIndex].set_index(this->tindex);
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
	if (this->tindex == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return ;
	}
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
	if (std::cin.eof()) {
		std::cout << "Exiting program..." << std::endl;
		return ;
	}
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