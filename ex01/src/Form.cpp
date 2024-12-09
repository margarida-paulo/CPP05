#include "../ex01/includes/Form.hpp"

//ORTHODOX CANONICAL FORM

//Constructors
Form::Form() : _signed(false), _gradeToSign(75), _gradeToExecute(75){
	std::cout << "Default Form constructor was called." << std::endl;
	std::cout << *this << std::endl;
}

Form::Form(Form &other) : _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
	std::cout << "Copy Form constructor was called." << std::endl;
	// Copy parameters. Don't forget shallow and deep copies!
	*this = other;
}

Form::Form(int gradeToSign, int gradeToExecute) : _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	std::cout << "Parameters Form constructor was called." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << *this << std::endl;
}


//Destructor

Form::~Form(){
	std::cout << "Form destructor was called." << std::endl;
}


//Operators

Form &Form::operator=(Form &other){
	if (this != &other){
		// Copy parameters. Don't forget shallow and deep copies!
		_signed = other._signed;
		// DON'T USE, DOESN'T COPY YJE OTHER ATTRIBUTES CAUSE THEY ARE CONST.
		std::cout << "Copy assignment operator called. DON'T USE IT, DOESN'T COPY THE CONST VALUES!" << std::endl;
	}
	return *this;
}

// Getters and Setters
std::string Form::getName() const{
	return _name;
}
int Form::getGradeToSign() const{
	return _gradeToSign;
}
int Form::getGradeToExecute() const{
	return _gradeToExecute;
}

bool Form::isSigned() const{
	return _signed;
}

// Other Functions

const char* Form::GradeTooHighException::what() const throw(){
	return "The grade is too high\n";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "The grade is too low\n";
}

std::ostream &operator<<(std::ostream &os, Form &object){
	os << "Form signed: ";
	if (object.isSigned() == true)
		os << "Yes" << std::endl;
	else
		os << "No" << std::endl;
	os << "Grade to sign: " << object.getGradeToSign() << std::endl;
	os << "Grade to execute: " << object.getGradeToExecute() << std::endl;
	return os;
}

void Form::beSigned(Bureaucrat &bureauGuy){
	if (bureauGuy.getGrade() <= this->getGradeToSign()){
		_signed = true;
		bureauGuy.signForm(true, *this, NULL);
	}
	else {
		bureauGuy.signForm(false, *this, "grade to sign was too low");
		throw GradeTooLowException();
	}
}
