#include "../includes/GradeTooLowException.hpp"

const char* GradeTooLowException::what() const throw(){
	return "The grade is too low\n";
}
