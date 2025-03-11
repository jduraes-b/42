/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:44:12 by jduraes-          #+#    #+#             */
/*   Updated: 2025/03/11 19:28:37 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& v, int tofind)
{
	typename T::iterator it = std::find(v.begin(), v.end(), tofind);
	if (it == v.end())
		throw std::string("member not found");
	return it;
}

#endif
