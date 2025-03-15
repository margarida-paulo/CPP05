#define INVALID 0
#define SCFSIGN 1
#define RRFSIGN 2
#define PPFSIGN 3
#define SCFEXEC 4
#define RRFEXEC 5
#define PPFEXEC 6
#define INCREASEGRADE 7
#define DECREASEGRADE 8
#define EXIT 9


#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"


int safeOnlyNumbersInput(){
	std::string input;
	std::getline(std::cin, input);
	size_t i = 0;
	if (input.size() > 0 && (input[0] == '-' || input[0] == '+'))
		i++;
    for (; i < input.size(); i++) {
        if (std::isdigit(input[i]) == 0){
			std::cout << "Invalid number input. Please insert a valid number." << std::endl;
			return safeOnlyNumbersInput();
		}
    }
	try{
		return atoi(input.c_str());
	} catch (std::exception &e){
		std::cout << "Invalid number input. Please insert a valid number." << std::endl;
		return safeOnlyNumbersInput();
	}
}

int menu(Bureaucrat &guy){
	std::cout << guy;
	std::cout << std::endl << "╋━━━━━━━━━━━━━━━━━━━━━━━━━╋" << std::endl;
	std::cout << "┃ -1: Decrement the grade ┃" << std::endl;
	std::cout << "┃ 1: Increment the grade  ┃" << std::endl;
	std::cout << "┃ 2: Sign a Form          ┃" << std::endl;
	std::cout << "┃ 3: Execute a Form       ┃" << std::endl;
	std::cout << "┃ 4: EXIT                 ┃" << std::endl;
	std::cout << "╋━━━━━━━━━━━━━━━━━━━━━━━━━╋" << std::endl << std::endl;;
	int operation = safeOnlyNumbersInput();
	int form;
	switch(operation){
		case 1:
			return INCREASEGRADE;
			break;
		case -1:
			return DECREASEGRADE;
			break;
		case 2:
			std::cout << "1: Sign ShrubberyCreationForm" << std::endl;
			std::cout << "2: Sign RobotomyRequestForm" << std::endl;
			std::cout << "3: Sign PresidentialPardonForm" << std::endl;
			form = safeOnlyNumbersInput();
			switch(form){
				case 1:
					return SCFSIGN;
					break;
				case 2:
					return RRFSIGN;
					break;
				case 3:
					return PPFSIGN;
					break;
				default:
					std::cout << "Invalid input." << std::endl;
					return INVALID;
			}
			break;
		case 3:
			std::cout << "1: Execute ShrubberyCreationForm" << std::endl;
			std::cout << "2: Execute RobotomyRequestForm" << std::endl;
			std::cout << "3: Execute PresidentialPardonForm" << std::endl;
			form = safeOnlyNumbersInput();
			switch(form){
				case 1:
					return SCFEXEC;
					break;
				case 2:
					return RRFEXEC;
					break;
				case 3:
					return PPFEXEC;
					break;
				default:
					return INVALID;
			}
			break;
		case 4:
			return EXIT;
			break;
		default:
			return INVALID;
	}
}


int main(){
	try{

		std::cout << "╋━━━━━━━━━━━━━━━━━━━━━━━━━━╋" << std::endl;
		std::cout << "┃ Insert Bureaucrat's name ┃" << std::endl;
		std::cout << "╋━━━━━━━━━━━━━━━━━━━━━━━━━━╋" << std::endl << std::endl;
		std::string name;
		std::getline(std::cin, name);
		std::cout << std::endl << "╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋" << std::endl;
		std::cout << "┃ Insert Bureaucrat's grade. Must be between 1 and 150, or it will end the program ┃" << std::endl;
		std::cout << "╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋" << std::endl << std::endl;
	
		int grade = safeOnlyNumbersInput();

		Bureaucrat guy(name, grade);
		
		std::cout << std::endl << "╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋" << std::endl;
		std::cout << "┃ Insert the name of the target ┃" << std::endl;
		std::cout << "╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋" << std::endl << std::endl;

		std::string target;
		std::getline(std::cin, target);


		ShrubberyCreationForm SCForm(target);
		RobotomyRequestForm RRForm(target);
		PresidentialPardonForm PPForm(target);
		std::cout << "ShrubberyCreationForm, RobotomyRequestForm and PresidentialPardonForm created." << std::endl;
		while (true){
			switch(menu(guy)){
				case INCREASEGRADE:
					guy.incrementGrade();
					break;
				case DECREASEGRADE:
					guy.decrementGrade();
					break;
				case SCFSIGN:
					SCForm.beSigned(guy);
					break;
				case RRFSIGN:
					RRForm.beSigned(guy);
					break;
				case PPFSIGN:
					PPForm.beSigned(guy);
					break;
				case SCFEXEC:
					guy.executeForm(SCForm);
					break;
				case RRFEXEC:
					guy.executeForm(RRForm);
					break;
				case PPFEXEC:
					guy.executeForm(PPForm);
					break;
				case INVALID:
					std::cout << "Invalid input." << std::endl;
					break;
				default:
					return (0);
			}
		}

	} catch (std::exception &e){
		std::cout << e.what();
	}
}