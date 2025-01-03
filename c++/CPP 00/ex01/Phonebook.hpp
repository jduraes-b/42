/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:51:28 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/09 17:50:31 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Contacts.hpp"

class Phonebook
{
	private:
		int	tindex;
		Contacts contacts[8];
		void 	update_index();
		std::string	format(std::string src);
		void	clear_curr();
		bool getInput(const std::string& prompt, std::string& input, void (Contacts::*setter)(const std::string), Contacts& contact, int& tindex, Phonebook& phonebook);

	public:
		Phonebook();
		~Phonebook();
		void	add_contact();
		void	search();

};

# endif
