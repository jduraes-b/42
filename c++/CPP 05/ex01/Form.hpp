/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:09:11 by jduraes-          #+#    #+#             */
/*   Updated: 2024/12/27 19:38:32 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool	_issigned;
		const int	_signreq;
		const int	_execreq;

	public:
		Form();
		Form(std::string name, int sign, int exec);
		~Form();
		int		getSignReq() const;
		std::string	getFormName() const;
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

std::ostream& operator<<(std::ostream &os, const Form &f);

#endif
