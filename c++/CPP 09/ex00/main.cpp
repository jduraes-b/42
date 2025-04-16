/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:41:30 by jduraes-          #+#    #+#             */
/*   Updated: 2025/04/16 19:59:01 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

void	evaluate(BitcoinExchange& exchange, char* input)
{
	std::ifstream infile(input);
    if (!infile.is_open())
        throw std::runtime_error("could not open file.\n");
    std::string line;
	std::getline(infile, line);
	if (line != "line | value")
		throw std::runtime_error("first line should be 'line | value'.");
    while (std::getline(infile, line))
    {
        if (line.empty())
			throw std::runtime_error("empty line.\n");
		std::string	edate = line.substr(0, 10);
		if (!exchange.isValidDate(edate))
			throw std::runtime_error("bad input -> " + edate);
		if (line.substr(10,13) != " | ")
			throw std::runtime_error("bad input -> " line);
		std::string	evalue = line.substr(13);
		if (std::atof(exchange.parseValue(evalue).c_str()) > 1000)
			throw std::runtime_error("bad input -> " + evalue);
		exchange.eval(edate, evalue);
	}
}

int main(int argc, char** argv)
{
    if (argc != 3)
        return 1;
    try
    {
        // Create a BitcoinExchange object with a test CSV file
        BitcoinExchange exchange(argv[1]);

        // Print the loaded data
        std::cout << "Loaded data:" << std::endl;
        const std::map<std::string, float>& data = exchange.getData();
        for (std::map<std::string, float>::const_iterator it = data.begin(); it != data.end(); ++it)
        {
            std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
        }
		evaluate(exchange, argv[2]);
    }
    catch (const std::exception& e)
    {
        // Catch and print any exceptions
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}