/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:48:26 by jduraes-          #+#    #+#             */
/*   Updated: 2025/04/22 21:42:03 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	_data = other._data;
}

RPN& RPN::operator=(const RPN& other)
{
	if (_data != other._data)
		_data = other._data;
	return *this;
}

RPN::~RPN()
{
}

void	RPN::solve(char* input)
{
	size_t l = std::strlen(input);
    for (size_t i = 0; i < l; ++i)
    {
        if (input[i] == ' ')
            continue;
		if (input[i] > 47 && input[i] < 58)
			_data.push(input[i] - 48);
		else if (std::strchr("-+/*", input[i]))
		{
			if (_data.size() < 2)
				throw std::exception();
			int a = _data.top(); _data.pop();
			int b = _data.top(); _data.pop();
			switch(input[i])
			{
				case '+':	_data.push(a + b); break;
                case '-':	_data.push(a - b); break;
                case '*':	_data.push(a * b); break;
                case '/':	if (b != 0)
								_data.push(a / b);
							else
								throw std::exception();
			}
		}
	}
	if (_data.size() != 1)
		throw std::exception();
}

int	RPN::result()
{
	return _data.top();
}
