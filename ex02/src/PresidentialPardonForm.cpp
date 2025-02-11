// PresidentialPardonForm.cpp
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5) {
  std::cout << "Default PresidentialPardonForm constructor was called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5) {
  std::cout << "Target PresidentialPardonForm constructor was called." << std::endl;
  this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) {
	this->setTarget(other.getTarget());
}

PresidentialPardonForm::~PresidentialPardonForm() {
//  std::cout << "PresidentialPardonForm destructor was called." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other) {
	// CONST PARAMETERS, DON'T USE, WON'T MAKE AN ACTUAL COPY!
	if (this != &other)
		this->setTarget(other.getTarget());
	return *this;
}

void PresidentialPardonForm::execute (Bureaucrat const &executor) const{
	try {
		checkRequirements(executor);
	  } catch (const AForm::GradeTooLowException &e){
		std::cout << e.what() << std::endl;
		return;
	  } catch (const AForm::FormNotSignedException &e) {
		std::cout << e.what() << std::endl;
		return;
	  }
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
