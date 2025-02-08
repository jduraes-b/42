/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:24:18 by jduraes-          #+#    #+#             */
/*   Updated: 2025/02/08 20:12:17 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

static bool /*ScalarConverter::*/checkdumb(std::string const input)
{
    if (input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff") 
    {
    	std::cout	<< "char: impossible" << std::endl
        			<< "int: impossible" << std::endl
					<< "float: " << input[0] << "inff" << std::endl
        			<< "double: " << input[0] << "inf" << std::endl;
        return (true);
    }
	else if (input == "inf" || input == "inff")
	{
		std::cout	<< "char: impossible" << std::endl
					<< "int: impossible" << std::endl
					<< "float: " << "inff" << std::endl
					<< "double: " << "inf" << std::endl;
		return (true);
	}
    else if (input == "nan") 
	{
        std::cout	<< "char: impossible" << std::endl
        			<< "int: impossible" << std::endl
        			<< "float: nanf" << std::endl
        			<< "double: nan" << std::endl;
        return (true);
    }
    return (false);
}

void	tryChar(std::string const input)
{
	try
	{
		if (input.length() == 1 && !std::isdigit(input[0]))
			std::cout << "char: '" << input[0] << "'" << std::endl;
		else
		{
			std::stringstream ss(input);
			int i;
			ss >> i;
			if (ss.fail() || !ss.eof() || i < 0 || i > 127)
				throw std::exception();
			else if (std::isprint(i))
				std::cout << "char: " << static_cast<char>(i) << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
		}	
	}
	catch(const std::exception& e) {
		std::cout << "char: impossible" << std::endl;
	}
}

void tryInt(std::string const input)
{
    try
    {
        std::stringstream ss(input);
        double d;
        ss >> d;
        if (ss.fail() || !ss.eof())
            throw std::exception();
        if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
            throw std::exception();
        int i = static_cast<int>(d);
        std::cout << "int: " << i << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "int: impossible" << std::endl;
    }
}

void	tryFloat(std::string const input)
{
	try
	{
		std::stringstream ss(input);
		float f;
		ss >> f;
		if (ss.fail() || !ss.eof())
			throw std::exception();
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "float: impossible" << std::endl;
	}
}

void	tryDouble(std::string const input)
{
	try
	{
		//std::string	temp = input;
		//if (input[input.length() -1] == 'f')
        //    temp.erase(temp.length() - 1);
		std::stringstream ss(input);
		double d;
		ss >> d;
		if (ss.fail() || !ss.eof())
			throw std::exception();
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << "double: impossible" << std::endl;
	}
}

void	ScalarConverter::convert(std::string const input)
{
	std::cout << "Input: " << input << std::endl;
	if (checkdumb(input))
		return ;
	std::string	temp = input;
	if (input[input.length() -1] == 'f')
        temp.erase(temp.length() - 1);
	tryChar(temp);
	tryInt(temp);
	tryFloat(temp);
	tryDouble(temp);
}