#include "includes/Bureaucrat.hpp"
#include "exceptions/includes/exceptions.hpp"

int main(){
	try{
		Bureaucrat("Maggie", 10);
		//Bureaucrat("Cami", -1);
		Bureaucrat("Pouya", 160);
	} catch (std::exception &e){
		std::cout << e.what();
	}
}
