/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:31:08 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/20 19:43:58 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other){
		Form::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecReq())
		throw GradeTooLowException();
	else if (!this->_issigned)
		throw UnsignedFormException();
	else 
	{
		std::ofstream file;
		file.open((this->target + "_shrubbery").c_str());
		file << "      +x      " << std::endl;
		file << "      /\\      " << std::endl;
		file << "     /\\o\\     " << std::endl;
		file << "    /\\/\\/\\    " << std::endl;
		file << "   /o/\\/\\0\\   " << std::endl;
		file << "  /\\O\\/\\o\\/\\  " << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << "      __      " << std::endl;
		file << std::endl;
		file.close();
	}
}
