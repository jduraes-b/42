/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:51:28 by jduraes-          #+#    #+#             */
/*   Updated: 2024/08/25 20:49:47 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contacts.hpp"

class Phonebook
{
	private:
		int	tindex = 0;
		Contacts contacts[8];

	public:
		Phonebook();
		~Phonebook();
		void	add_contact();
		void	search();
		void 	update_index();
};

# endif