/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:09:11 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/20 20:16:30 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <string>

class Bureaucrat;

class Form
{
	protected:
		const std::string	_name;
		bool	_issigned;
		const int	_signreq;
		const int	_execreq;

	public:
		Form();
		Form(std::string name, int sign, int exec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		virtual ~Form();
		int		getSignReq() const;
		int		getExecReq() const;
		std::string	getFormName() const;
		void	beSigned(Bureaucrat &b);
		void	print(std::ostream &os) const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
		    	
		class GradeTooHighException : public std::exception {
    		public:
    		    const char* what() const throw();
    	};
    	class GradeTooLowException : public std::exception {
    		public:
    		    const char* what() const throw();
    	};
		class UnsignedFormException : public std::exception {
			public:
			    const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Form &f);

#endif
