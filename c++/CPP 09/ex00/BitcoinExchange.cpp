/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:01:20 by jduraes-          #+#    #+#             */
/*   Updated: 2025/04/10 19:27:45 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& file)
{
	std::ifstream infile(file.c_str());
	if(!infile.is_open())
		throw std::runtime_error("Couldn't open file.\n");
	std::string	line;
	while(std::getline(infile, line))
	{
		std::istringstream ss(line);
		_data[extField(ss)] = static_cast<float>(std::atof(extField(ss).c_str()));	
	}
}

static std::string extField(std::istringstream& ss)
{
    std::string field;
    std::getline(ss, field, ',');
    return field;
}