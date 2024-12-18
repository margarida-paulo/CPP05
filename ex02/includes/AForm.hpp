#ifndef AFORM
# define AFORM

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		// ORTHODOX CANONICAL FORM
		AForm(); // Default constructor
		AForm(AForm &other); // Copy constructor
		~AForm(); // Destructor
		AForm &operator=(AForm &other); // Copy assignment operator


		AForm(std::string name, int gradeToSign, int gradeToExecute);

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

std::ostream &operator<<(std::ostream &os, AForm &object);

#endif
