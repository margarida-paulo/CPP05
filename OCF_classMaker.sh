#!/bin/bash

#Ask for object name
read -p "Enter the name of the class: " CLASS_NAME
read -e -p "Enter the folder for the .hpp file: " HPP_FOLDER
read -e -p "Enter the folder for the .cpp file: " CPP_FOLDER
read -e -p "Enter the relative path from the cpp directory to the place where the hpp directory is: " RELATIVE_PATH_INCLUDE


HPP_FILE="$HPP_FOLDER/$CLASS_NAME.hpp"
CPP_FILE="$CPP_FOLDER/$CLASS_NAME.cpp"

echo "#include <string>
#include <iostream>

class $CLASS_NAME
{
	private:
		// Attributes

	public:
		// ORTHODOX CANONICAL FORM
		$CLASS_NAME(); // Default constructor
		$CLASS_NAME($CLASS_NAME &other); // Copy constructor
		~$CLASS_NAME(); // Destructor
		$CLASS_NAME &operator=($CLASS_NAME &other); // Copy assignment operator

		// Getters and setters:

		// Other functions:

};" > $HPP_FILE

echo "#include \"$RELATIVE_PATH_INCLUDE/$HPP_FILE\"

//ORTHODOX CANONICAL FORM

//Constructors
$CLASS_NAME::$CLASS_NAME(){
	std::cout << \"Default $CLASS_NAME constructor was called.\" << std::endl;
}

$CLASS_NAME::$CLASS_NAME($CLASS_NAME &other){
	std::cout << \"Copy $CLASS_NAME constructor was called.\" << std::endl;
	// Copy parameters. Don't forget shallow and deep copies!
}

//Destructor

$CLASS_NAME::~$CLASS_NAME(){
	std::cout << \"$CLASS_NAME destructor was called.\" << std::endl;
}


//Operators

$CLASS_NAME &$CLASS_NAME::operator=($CLASS_NAME &other){
	if (this != &other){
		// Copy parameters. Don't forget shallow and deep copies!
	}
	return *this;
}
" >> $CPP_FILE

if ![ -f "$HPP_FILE" ]; then
	echo "Oops! Something went wrong with the .hpp file. 😕"
else if ![ -f "$CPP_FILE" ]; then
	echo "Oops! Something went wrong with the .cpp file. 😕"
else
	echo "File '$HPP_FILE' created and content written successfully! 📝"
fi

done
