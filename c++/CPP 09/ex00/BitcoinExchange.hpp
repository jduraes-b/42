/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:38:13 by jduraes-          #+#    #+#             */
/*   Updated: 2025/04/15 20:10:31 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include <fstream>

class	BitcoinExchange  //MAP
{
	private:
		std::map<std::string, float>	_data;
	public:
		BitcoinExchange(const std::string& file);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		const std::map<std::string, float>& getData() const;
		void	eval(std::string& toeval);
};

# endif