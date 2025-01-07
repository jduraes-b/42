/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:46:40 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/07 19:43:55 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecReq())
		throw GradeTooLowException();
	else if (!this->_issigned)
		throw UnsignedFormException();
	else 
	{
		std::cout<< "*drilling noises*" <<std::endl;
		std::srand(std::time(0) + getpid());
		if (rand() % 2 == 0)
			std::cout<< "Target successfuly robotomized." <<std::endl;
		else
			std::cout<< "Robotomy failed." <<std::endl;
	}
}

