#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"


//Constructors
Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150){
	std::cout << "Default Bureaucrat constructor was called." << std::endl;
	showStats();
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
	std::cout << "Parameters Bureaucrat constructor was called." << std::endl;
	this->setGrade(grade);
	showStats();
}

Bureaucrat::Bureaucrat(Bureaucrat &other): _name(other._name), _grade(other._grade){
	std::cout << "Copy Bureaucrat constructor was called." << std::endl;
	showStats();
}


//Destructor

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor was called." << std::endl;
}


//Operators

//The name is constant, it can't change. Therefore the operator= doesn't make sense, it
// should technically be deleted, but since the subject requires it, I'm gonna implement
// it, but it only changes the grade.
Bureaucrat &Bureaucrat::operator=(Bureaucrat &other){
	if (this != &other){
		_grade = other._grade;
	}
	return *this;
}


void Bureaucrat::setGrade(int grade){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

std::string Bureaucrat::getName() const{
	return _name;
}

void Bureaucrat::showStats(){
	std::cout << std::endl << *this << std::endl;
}


void Bureaucrat::incrementGrade(){
	this->setGrade(_grade-1);

}

void Bureaucrat::decrementGrade(){
	this->setGrade(_grade+1);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj){
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "The grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "The grade is too low\n";
}

void Bureaucrat::signForm(bool gotSigned, Form form, std::string reason){
	if (gotSigned)
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	else
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << reason << "." << std::endl;
}


