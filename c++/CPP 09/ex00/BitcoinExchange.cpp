/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:01:20 by jduraes-          #+#    #+#             */
/*   Updated: 2025/04/16 19:51:08 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <cstdlib>

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 2009 || year > 2025 || month < 1 || month > 12 || day < 1)
        return false;
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && (year % 4 == 0))
        daysInMonth[1] = 29;
    if (day > daysInMonth[month - 1])
        return false;
    return true;
}

std::string BitcoinExchange::parseValue(const std::string& value)
{
    if (value.empty())
        throw std::runtime_error("empty value field");
    for (size_t i = 0; i < value.length(); ++i)
    {
        if (!std::isdigit(value[i]) && value[i] != '.')
            throw std::runtime_error("bad input -> " + value);
    }
    float result = static_cast<float>(std::atof(value.c_str()));
    if (result < 0)
        throw std::runtime_error("not a positive number.");
    return value;
}

static std::string extField(std::string line, int t)
{
    std::string field;
	if(t==0)
	{	 
		field = line.substr(0, 10);
		//std::cout<<"line: " + field + "\n";
		if (field.empty())
    		throw std::runtime_error("empty field\n");
		if (!isValidDate(field))
			throw std::runtime_error("bad input ->" + field);
	}
	else
		field = parseValue(line.substr(11));
	return field;
}

BitcoinExchange::BitcoinExchange(const std::string& file)
{
	std::ifstream infile(file.c_str());
	if(!infile.is_open())
		throw std::runtime_error("couldn't open file.");
	std::string	line;
	std::getline(infile, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("first line of CSV should be: date,exchange_rate; not " + line);
	while(std::getline(infile, line))
	{
		//std::istringstream ss(line);
		_data[extField(line,0)] = static_cast<float>(std::atof(extField(line,1).c_str()));	
	}
}

BitcoinExchange::~BitcoinExchange()
{
}
const std::map<std::string, float>& BitcoinExchange::getData() const
{
    return _data;
}

void	BitcoinExchange::eval(std::string& edate, std::string& evalue)
{
    float inputValue = std::atof(evalue.c_str());
    std::map<std::string, float>::const_iterator it = _data.find(edate);
    if (it != _data.end())
    {
        float exchangeRate = it->second;
        float result = inputValue * exchangeRate;
        std::cout << edate << " => " << evalue << " = " << result << std::endl;
    }
    else
    {
        std::cerr << "Error: missing date: " << edate << std::endl;
    }
}
