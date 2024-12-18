#include "MyLib.hpp"

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