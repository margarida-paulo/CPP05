#include "../ex01/includes/Form.hpp"

//ORTHODOX CANONICAL FORM

//Constructors
Form::Form() : _signed(false), _gradeToSign(75), _gradeToExecute(75){
	std::cout << "Default Form constructor was called." << std::endl;
	showFormInfo();
}

Form::Form(Form &other) : _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute){
	std::cout << "Copy Form constructor was called." << std::endl;
	// Copy parameters. Don't forget shallow and deep copies!
	*this = other;
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

// Other Functions

void Form::showFormInfo(){
	std::cout << "Form signed: ";
	if (_signed == true)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;
		std::cout << "Grade to sign: " << _gradeToSign << std::endl;
		std::cout << "Grade to execute: " << _gradeToExecute << std::endl;
}
