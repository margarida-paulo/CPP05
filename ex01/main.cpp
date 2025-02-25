#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

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
		return std::stoi(input);
	} catch (std::exception &e){
		std::cout << "Invalid number input. Please insert a valid number." << std::endl;
		return safeOnlyNumbersInput();
	}
}

int main(){
	std::cout << "Insert Bureaucrat's name" << std::endl;
	std::string name;
	std::getline(std::cin, name);
	std::cout << "Insert Bureaucrat's grade. Must be between 1 and 150, or it will end the program." << std::endl;
	int grade = safeOnlyNumbersInput();
	std::cout << "Insert the form's name." << std::endl;
	std::string formName;
	std::getline(std::cin, formName);
	std::cout << "Insert the form's grade to sign. Must be between 1 and 150, or the program will end after all the input is inserted." << std::endl;
	int gradeToSign = safeOnlyNumbersInput();
	std::cout << "Insert the form's grade to execute. Must be between 1 and 150, or the program will end after all the input is inserted." << std::endl;
	int gradeToExecute = safeOnlyNumbersInput();

	try{
		Form form(formName, gradeToSign, gradeToExecute);
		Bureaucrat guy(name, grade);
		std::cout << form << std::endl;
		int increment = 0;
		while (increment != 2){
			std::cout << "Insert a 1 to increment the grade, a -1 to decrement it, or a 0 to sign the form. Insert 2 to exit." << std::endl;
			increment = safeOnlyNumbersInput();
			if (increment == -1)
				guy.decrementGrade();
			else if (increment == 1)
				guy.incrementGrade();
			else if (increment == 0)
				form.beSigned(guy);
			else if (increment == 2)
				continue;
			else
				std::cout << "Invalid input." << std::endl;
			std::cout << guy << std::endl;
			std::cout << form << std::endl;
		}

	} catch (std::exception &e){
		std::cout << e.what();
	}
}