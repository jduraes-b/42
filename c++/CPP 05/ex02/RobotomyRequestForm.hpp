/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:39:19 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/07 19:02:07 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : virtual public AForm
{
	private:
		std::string	target;
	
	public:
		RobotomyRequestForm(std::string	target);
		~RobotomyRequestForm();
		void	execute(Bureaucrat const & executor) const;
};

# endif

