/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:51:28 by jduraes-          #+#    #+#             */
/*   Updated: 2024/11/01 18:40:29 by jduraes-         ###   ########.fr       */
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

	public:
		Phonebook();
		~Phonebook();
		void	add_contact();
		void	search();
		void 	update_index();
		void	clear_curr();
		std::string	format(std::string src);
};

# endif