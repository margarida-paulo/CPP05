// PresidentialPardonForm.hpp
#ifndef PresidentialPardonForm_HPP_
#define PresidentialPardonForm_HPP_

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm &other);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(PresidentialPardonForm &other);
    virtual void execute (Bureaucrat const & executor) const;
};

#endif  // 
