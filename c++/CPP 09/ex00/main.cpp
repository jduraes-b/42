/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:41:30 by jduraes-          #+#    #+#             */
/*   Updated: 2025/04/14 20:37:31 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
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
    }
    catch (const std::exception& e)
    {
        // Catch and print any exceptions
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}