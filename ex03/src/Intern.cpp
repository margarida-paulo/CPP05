// Intern.cpp
#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

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
  std::string names[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
  AForm *forms[] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
  for (int i = 0; i < 3; i++) {
    if (type == types[i]) {
      std::cout << "Intern creates " << names[i] << std::endl;
      i++;
        while (i < 3){
          delete(forms[i]);
          i++;
        }
      return forms[i];
    }
    else
      delete(forms[i]);
  }
  std::cout << "Intern cannot create " << type << std::endl;
  return NULL;
}