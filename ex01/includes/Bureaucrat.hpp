#ifndef BUREAUCRAT
# define BUREAUCRAT

#include <string>
#include <iostream>

#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		//Constructors
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &other);

		//Destructor
		~Bureaucrat();

		//Operators
		Bureaucrat &operator=(Bureaucrat &other);

		//Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const throw();
		};

		/////////////////////////////////////////////////////////////////////////////

		void setGrade(int grade);
		int getGrade() const;
		std::string getName() const;
		void incrementGrade();
		void decrementGrade();

		void showStats();

		void signForm(bool gotSigned, Form form, std::string reason);


};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
