#include <string>
#include <iostream>

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		// ORTHODOX CANONICAL FORM
		Form(); // Default constructor
		Form(Form &other); // Copy constructor
		~Form(); // Destructor
		Form &operator=(Form &other); // Copy assignment operator

		// Getters and setters:

		// Other functions:
		void showFormInfo();

};
