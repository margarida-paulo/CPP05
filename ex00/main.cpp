#include "includes/Bureaucrat.hpp"

int main(){
	try{
		std::cout << "Best student:" << std::endl;
		Bureaucrat ryan("Ryan", 1);

		std::cout << "Worst student:" << std::endl;
		Bureaucrat mary("Mary", 130);

		//std::cout << "Best student tries to increase his grade:" << std::endl;
		//ryan.incrementGrade();
		for (int i = 0; i < 100; i++) {
			std::cout << "Worst student tries to decrease her grade:" << std::endl;
			mary.decrementGrade();
			mary.showStats();
		}

	} catch (std::exception &e){
		std::cout << e.what();
	}
}

