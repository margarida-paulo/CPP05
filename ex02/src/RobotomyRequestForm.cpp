// RobotomyRequestForm.cpp
#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) {
  std::cout << "Default RobotomyRequestForm constructor was called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45) {
  std::cout << "Target RobotomyRequestForm constructor was called." << std::endl;
  this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other) {
	this->setTarget(other.getTarget());
}
RobotomyRequestForm::~RobotomyRequestForm() {
// std::cout << "RobotomyRequestForm destructor was called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other) {
	// CONST PARAMETERS, DON'T USE, WON'T MAKE AN ACTUAL COPY!
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::execute (Bureaucrat const &executor) const{
	srand (time(NULL));
	int i = rand() % 2;
	try {
		checkRequirements(executor);
	  } catch (const AForm::GradeTooLowException &e){
		std::cout << e.what() << std::endl;
		return;
	  } catch (const AForm::FormNotSignedException &e) {
		std::cout << e.what() << std::endl;
		return;
	  }
	std::cout << "TRRRRRR-RRRRR-RRTRTRTTTT-TRRRRRR... *DRILLING NOISES*" << std::endl;
	if (i == 0)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed! You got lucky this time " << this->getTarget() <<"..." << std::endl;
}