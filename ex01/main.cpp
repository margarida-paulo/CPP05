#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

int main(){
	Form mainForm;
	Bureaucrat randomGuy("RandomChump", 100);
	mainForm.beSigned(randomGuy);
}
