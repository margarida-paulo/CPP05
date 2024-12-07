#include <string>
#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		//Constructors
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &other);

		//Destructor
		~Bureaucrat();

		//Operators
		Bureaucrat &operator=(Bureaucrat &other);

		void setGrade(int grade);
		int getGrade() const;
		std::string getName() const;
		void incrementGrade();
		void decrementGrade();

		void showStats();

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
