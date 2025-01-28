/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduraes- <jduraes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 20:09:11 by jduraes-          #+#    #+#             */
/*   Updated: 2025/01/28 21:15:34 by jduraes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

// Forward declaration of Bureaucrat class
class Bureaucrat;

class Form {
	private:
	    const std::string _name;
    	bool _issigned;
    	const int _signreq;
    	const int _execreq;

	public:
    	Form();
    	Form(std::string name, int sign, int exec);
    	Form(const Form &other);
    	Form &operator=(const Form &other);
    	~Form();
    	int getSignReq() const;
    	std::string getFormName() const;
    	void beSigned(Bureaucrat &b);
    	void print(std::ostream &os) const;

    class GradeTooHighException : public std::exception {
    	public:
    	    const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    	public:
        	const char* what() const throw();
    };

    class SignedFormException : public std::exception {
    	private:
        	mutable std::string msg;
    	public:
    	    SignedFormException(Bureaucrat &b, const std::string &formName) throw();
    	    virtual const char* what() const throw();
    	    ~SignedFormException() throw() {}
    };

    class LackGradeException : public std::exception {
    	private:
    	    mutable std::string msg;
    	public:
    	    LackGradeException(Bureaucrat &b, const std::string &formName) throw();
    	    virtual const char* what() const throw();
    	    ~LackGradeException() throw() {}
    };
};

std::ostream& operator<<(std::ostream &os, const Form &f);

#endif
