// Intern.hpp
#ifndef Intern_HPP_
#define Intern_HPP_

#include <iostream>
#include <string>

#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(Intern &other);
    ~Intern();
    Intern &operator=(Intern &other);
    // Add public members here
    AForm *makeForm(std::string type, std::string target) const;
};

#endif  // 
