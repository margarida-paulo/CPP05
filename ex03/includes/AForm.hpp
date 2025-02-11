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
		std::string _target;
		
		public:
		// ORTHODOX CANONICAL FORM
		AForm(); // Default constructor
		AForm(AForm &other); // Copy constructor
		virtual ~AForm(); // Destructor
		AForm &operator=(AForm &other); // Copy assignment operator
		
		
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		
		// Getters and setters:
		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool isSigned() const;
		std::string getTarget() const;
		void setTarget(std::string target);
		
		// Other functions:
		typedef AForm* (*FormCreator)(const std::string& target);
		void beSigned(Bureaucrat &bureauGuy);
		virtual void execute (Bureaucrat const & executor) const = 0;
		void checkRequirements(Bureaucrat const &guy) const;
		static AForm* createShrubberyCreationForm(const std::string& target);
		static AForm* createRobotomyRequestForm(const std::string& target);
		static AForm* createPresidentialPardonForm(const std::string& target);


		//Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
			virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception{
			public:
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, AForm &object);

#endif
