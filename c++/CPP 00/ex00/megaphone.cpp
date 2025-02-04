/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 19:21:25 by jduraes-          #+#    #+#             */
/*   Updated: 2024/10/17 19:35:19 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

/*char ft_uppercase(char c)
{
    if (c > 96 && c < 123)
        return (c - 32);
    return (c);
}*/

int main(int argc, char **argv)
{
    int i = 0;
    int j = -1;

    if (argc == 1)
        std::cout << "*LOUD AND UNBEARABLE NOISE*\n";
    else
    {
        while(argv[++i])
        {
            j = -1;
            while(argv[i][++j])
			{
				//if (argv[i][j] == ' ')
				//	std::cout << ' ';
				//else
                	std::cout<<static_cast<char>(std::toupper(argv[i][j]));
			}
		}
        std::cout << std::endl;
    }
    return (0);
}
