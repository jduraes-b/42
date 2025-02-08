/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:12:04 by jduraes-          #+#    #+#             */
/*   Updated: 2025/02/08 19:58:05 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>	// std::setprecision
//# include <limits>
//# include <cmath>
//# include <cfloat>
//# include <cstdlib>
# include <climits>
# include <sstream>
//# include <cctype>
# include <exception>

class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter const &other);
	ScalarConverter &operator=(ScalarConverter const &other);
	//bool ScalarConverter::checkdumb(std::string const input);

public:
	static void convert(std::string const input);
};

# endif
