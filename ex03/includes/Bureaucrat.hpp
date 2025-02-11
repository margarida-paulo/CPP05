#ifndef BUREAUCRAT
# define BUREAUCRAT

#include <string>
#include <iostream>

#include "AForm.hpp"

class AForm;
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

		void signAForm(bool gotSigned, AForm *aform, std::string reason);
		void executeForm(AForm const & form);


};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
