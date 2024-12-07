#include "../includes/GradeTooHighException.hpp"

const char* GradeTooHighException::what() const throw(){
	return "The grade is too high\n";
}
