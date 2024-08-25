/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:37:26 by jduraes-          #+#    #+#             */
/*   Updated: 2024/08/25 20:49:49 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contacts::Contacts()
{
}

Contacts::~Contacts()
{
}

void	Contacts::set_index(int index)
{
	this->index = index;
}

void	Contacts::set_fname(std::string fname)
{
	this->_firstname = fname;
}

void	Contacts::set_lname(std::string lname)
{
	this->_lastname = lname;
}

void	Contacts::set_nick(std::string nick)
{
	this->_nickname = nick;
}

void	Contacts::set_phonenr(std::string phonenr)
{
	this->_phonenr = phonenr;
}

void	Contacts::set_secret(std::string secret)
{
	this->_darksecret = secret;
}

std::string	Contacts::get_fname()
{
	return (this->_firstname);
}

std::string	Contacts::get_lname()
{
	return (this->_lastname);
}

std::string	Contacts::get_nick()
{
	return (this->_nickname);
}

std::string	Contacts::get_phonenr()
{
	return (this->_phonenr);
}

std::string	Contacts::get_secret()
{
	return (this->_darksecret);
}

int	Contacts::get_index()
{
	return (this->index);
}
