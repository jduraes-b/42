/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:34:23 by jduraes-          #+#    #+#             */
/*   Updated: 2024/08/25 20:49:48 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contacts
{
	private:
		int	index;
		std::string	_firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenr;
		std::string	_darksecret;

	public:
		Contacts();
		~Contacts();
		void	set_index(int index);
		void	set_fname(std::string fname);
		void	set_lname(std::string lname);
		void	set_nick(std::string nick);
		void	set_phonenr(std::string phonenr);
		void	set_secret(std::string secret);
		std::string	get_fname();
		std::string	get_lname();
		std::string	get_nick();
		std::string	get_phonenr();
		std::string	get_secret();
		int	get_index();
};

#endif