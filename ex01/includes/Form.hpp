#ifndef FORM
# define FORM

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		// ORTHODOX CANONICAL FORM
		Form(); // Default constructor
		Form(Form &other); // Copy constructor
		~Form(); // Destructor
		Form &operator=(Form &other); // Copy assignment operator


		Form(int gradeToSign, int gradeToExecute);
		// Getters and setters:
		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;

		// Other functions:
		void beSigned(Bureaucrat &bureauGuy);

		//Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const throw();
		};

};

std::ostream &operator<<(std::ostream &os, Form &object);

#endif
