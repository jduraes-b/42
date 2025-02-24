/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:40:47 by jduraes-          #+#    #+#             */
/*   Updated: 2025/02/24 19:33:58 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>

template <typename T>
void swap(T &t1, T &t2)
{
	T ttemp = t1;
	t1 = t2;
	t2 = ttemp;
}

template<typename T>
T min(const T &t1, const T &t2) {
	return t1 < t2 ? t1 : t2;
}

template <typename T>
T max(const T &t1, const T &t2) {
	return t1 > t2 ? t1 : t2;
}

# endif
