/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:09:11 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/03 19:50:48 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAFORM_HPP
# define AAFORM_HPP

#include <exception>
#include <string>

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		bool	_issigned;
		const int	_signreq;
		const int	_execreq;

	public:
		AForm();
		AForm(std::string name, int sign, int exec);
		~AForm();
		int		getSignReq() const;
		std::string	getAFormName() const;
		void	beSigned(Bureaucrat &b);
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

std::ostream& operator<<(std::ostream &os, const AForm &f);

#endif
