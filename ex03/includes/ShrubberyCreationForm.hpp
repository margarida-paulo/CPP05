// ShrubberyCreationForm.hpp
#ifndef ShrubberyCreationForm_HPP_
#define ShrubberyCreationForm_HPP_

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(ShrubberyCreationForm &other);
    virtual void execute (Bureaucrat const & executor) const;
};

#endif  // 
