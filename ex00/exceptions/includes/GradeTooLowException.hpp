#ifndef GRADETOOLOWEXCEPTION
# define GRADETOOLOWEXCEPTION

#include <exception>

class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
};

#endif
