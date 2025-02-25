#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

//ORTHODOX CANONICAL FORM

//Constructors
AForm::AForm() :  _name("Default AForm"), _signed(false), _gradeToSign(75), _gradeToExecute(75){
	std::cout << "Default AForm constructor was called." << std::endl;
	std::cout << *this << std::endl;
}

AForm::AForm(AForm &other) : _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
	std::cout << "Copy AForm constructor was called." << std::endl;
	*this = other;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	std::cout << "Parameters AForm constructor was called." << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << *this << std::endl;
}


//Destructor

AForm::~AForm(){
//	std::cout << "AForm destructor was called." << std::endl;
}


//Operators

AForm &AForm::operator=(AForm &other){
	if (this != &other){
		_signed = other._signed;
		_target = other._target;
		// DON'T USE, DOESN'T COPY THE OTHER ATTRIBUTES CAUSE THEY ARE CONST.
		std::cout << "Copy assignment operator called. DON'T USE IT, DOESN'T COPY THE CONST VALUES!" << std::endl;
	}
	return *this;
}

// Getters and Setters
std::string AForm::getName() const{
	return _name;
}
int AForm::getGradeToSign() const{
	return _gradeToSign;
}
int AForm::getGradeToExecute() const{
	return _gradeToExecute;
}

bool AForm::isSigned() const{
	return _signed;
}

// Other Functions

const char* AForm::GradeTooHighException::what() const throw(){
	return "The grade is too high.\n";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "The grade is too low.\n";
}

const char* AForm::FormNotSignedException::what() const throw(){
	return "The form is not signed.\n";
}

std::ostream &operator<<(std::ostream &os, AForm &object){
	os << "AForm name: " << object.getName() << std::endl;
	os << "AForm signed: ";
	if (object.isSigned() == true)
		os << "Yes" << std::endl;
	else
		os << "No" << std::endl;
	os << "Grade to sign: " << object.getGradeToSign() << std::endl;
	os << "Grade to execute: " << object.getGradeToExecute() << std::endl;
	return os;
}

void AForm::beSigned(Bureaucrat &bureauGuy){
	if (_signed == true){
		std::cout << "AForm is already signed." << std::endl;
	}
	else if (bureauGuy.getGrade() <= this->getGradeToSign()){
		_signed = true;
		bureauGuy.signAForm(true, this, "signed successfully");
	}
	else {
		bureauGuy.signAForm(false, this, "grade to sign was too low");
		throw GradeTooLowException();
	}
}

void AForm::setTarget(std::string target){
	_target = target;
}

std::string AForm::getTarget() const{
	return _target;
}

void AForm::checkRequirements(Bureaucrat const &guy) const{
	if (_gradeToExecute < guy.getGrade()){
		std::cout << "Execution failed. ";
		throw GradeTooLowException();
	}
	else if (_signed == false) {
		std::cout << "Execution failed. ";
		throw FormNotSignedException();
	}
}

