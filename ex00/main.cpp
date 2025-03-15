#include "includes/Bureaucrat.hpp"

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

int main(){
	std::cout << "Insert Bureaucrat's name" << std::endl;
	std::string name;
	std::getline(std::cin, name);
	std::cout << "Insert Bureaucrat's grade. Must be between 1 and 150, or it will end the program." << std::endl;
	int grade = safeOnlyNumbersInput();

	try{
		Bureaucrat guy(name, grade);
		while (true){
			std::cout << "Insert a 1 to increment the grade, or a -1 to decrement it" << std::endl;
			int increment = safeOnlyNumbersInput();
			if (increment == -1)
				guy.decrementGrade();
			else if (increment == 1)
				guy.incrementGrade();
			else
				std::cout << "Invalid input." << std::endl;
			std::cout << guy;
		}

	} catch (std::exception &e){
		std::cout << e.what();
	}
}

