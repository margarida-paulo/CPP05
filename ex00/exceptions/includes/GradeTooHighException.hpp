#ifndef GRADETOOHIGHEXCEPTION
# define GRADETOOHIGHEXCEPTION
#include <exception>

class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
};

#endif