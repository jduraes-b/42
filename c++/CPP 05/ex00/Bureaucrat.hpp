/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:37:53 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/20 19:36:25 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;
	public:
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		const std::string&	getName() const;
		int	getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		void	print(std::ostream &os) const;
		
		class GradeTooHighException : public std::exception {
    		public:
    		    const char* what() const throw();
    	};
    	class GradeTooLowException : public std::exception {
    		public:
    		    const char* what() const throw();
    	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif