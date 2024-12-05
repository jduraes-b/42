/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:57:21 by jduraes-          #+#    #+#             */
/*   Updated: 2024/09/24 18:19:45 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
#include "Animal.hpp"

class Brain
{	
	private:
		std::string ideas[100];
	
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain &operator=(const Brain &other);
		std::string getIdea(int i) const;
		void setIdea(int i, std::string idea);
};

#endif
