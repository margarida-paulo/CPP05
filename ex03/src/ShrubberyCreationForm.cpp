// ShrubberyCreationForm.cpp

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
  std::cout << "Default ShrubberyCreationForm constructor was called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
  std::cout << "Target ShrubberyCreationForm constructor was called." << std::endl;
  this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) {
  this->setTarget(other.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  //std::cout << "ShrubberyCreationForm destructor was called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other) {
	// CONST PARAMETERS, DON'T USE, WON'T MAKE AN ACTUAL COPY!
	if (this != &other)
		this->setTarget(other.getTarget());
	return *this;
}

void ShrubberyCreationForm::execute (Bureaucrat const &executor) const{
  try {
    checkRequirements(executor);
  } catch (const AForm::GradeTooLowException &e){
    std::cout << e.what() << std::endl;
    return;
  } catch (const AForm::FormNotSignedException &e) {
    std::cout << e.what() << std::endl;
    return;
  }
  
  std::ofstream shrubberyFile(getTarget() + "_shrubbery");
  shrubberyFile << "              _{\\ _{\\{\\/}/}/}__\n" <<
"             {/{/\\}{/{/\\}(\\}{/\\} _\n" <<
"            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n" <<
"         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n" <<
"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n" <<
"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n" <<
"      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n" <<
"     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n" <<
"      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n" <<
"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n" <<
+"         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n" <<
"            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n" <<
"             {/{\\{\\{\\/}/}{\\{\\\\}/}\n" <<
"              {){/ {\\/}{\\/} \\}\\}\n" <<
"              (_)  \\.-'.-/\n" <<
"  .  '  .       _.-|-._ -|-._  .  '  .\n" <<
"              .'   |'- .-|   '.\n" <<
"  ..-'   ' .  '.   `-._.-�   .'  '  - .\n" <<
"   .-' '        '-._______.-'     '  .\n" << std::endl;
shrubberyFile.close();
}