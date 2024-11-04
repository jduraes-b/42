/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:44:00 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/03 20:01:18 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void replace(std::string &str, std::string s1, std::string s2)
{
	int	i = 0;

	while ((i = str.find(s1, i)) != -1)
	{
		str.erase(i, s1.size());
		str.insert(i, s2);
	}
}

int	main(int argc, char	**argv)
{
	if (argc != 4)
	{
		std::cout << "Error: Invalid number of arguments." << std::endl;
		return (1);
	}
	std::ifstream	infile;
	std::string	str;
	std::string	line;

	infile.open(argv[1]);
	if (!infile.is_open())
	{
		std::cout << "Error: Could not open file." << std::endl;
		return (1);
	}
	while (std::getline(infile, line))
	{
		str.append(line);
		if (infile.peek() != EOF)
           		str.append("\n");
	}
	infile.close();
	replace(str, argv[2], argv[3]);
	std::ofstream	outfile("outfile.txt");
	outfile << str;
	outfile.close();
	return (0);
}
