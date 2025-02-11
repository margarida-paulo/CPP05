// RobotomyRequestForm.hpp
#ifndef RobotomyRequestForm_HPP_
#define RobotomyRequestForm_HPP_

#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm &other);
    ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(RobotomyRequestForm &other);
    virtual void execute (Bureaucrat const & executor) const;
};

#endif  // 
