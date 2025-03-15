// Intern.cpp
#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/AForm.hpp"


Intern::Intern() {
  std::cout << "Default Intern constructor was called." << std::endl;
}

Intern::Intern(Intern &other) {
  (void)other;
}
Intern::~Intern() {
  std::cout << "Intern destructor was called." << std::endl;
}

Intern &Intern::operator=(Intern &other) {
  (void)other;
	return *this;
}

AForm *Intern::makeForm(std::string type, std::string target) const {
    std::string types[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm::FormCreator creators[] = {AForm::createShrubberyCreationForm, AForm::createRobotomyRequestForm, AForm::createPresidentialPardonForm};

    for (int i = 0; i < 3; i++) {
        if (type == types[i]) {
            std::cout << "Intern creates " << types[i] << std::endl;
            return creators[i](target);
        }
    }
    std::cout << "Intern cannot create " << type << std::endl;
    return NULL;
}