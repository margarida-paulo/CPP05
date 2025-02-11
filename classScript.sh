#!/bin/bash

echo "Enter the name of the class:"
read className

echo "Creating class $className in orthodox canonical form..."

echo "// $className.hpp"> $className.hpp
echo "#ifndef ${className}_HPP_" >> $className.hpp
echo "#define ${className}_HPP_" >> $className.hpp
echo "" >> $className.hpp
echo "#include <iostream>" >> $className.hpp
echo "#include <string>" >> $className.hpp
echo "" >> $className.hpp
echo "class $className {" >> $className.hpp
echo "public:" >> $className.hpp
echo "    $className();" >> $className.hpp
echo "    $className($className &other);" >> $className.hpp
echo "    ~$className();" >> $className.hpp
echo "    $className &operator=($className &other);" >> $className.hpp
echo "    // Add public members here" >> $className.hpp
echo "};" >> $className.hpp
echo "" >> $className.hpp
echo "#endif  // $className_HPP_" >> $className.hpp

echo "Created $className.hpp"

echo "// $className.cpp" > $className.cpp
echo "#include \"$className.hpp\"" >> $className.cpp
echo "" >> $className.cpp
echo "$className::$className() {" >> $className.cpp
echo "  std::cout << \"Default $className constructor was called.\" << std::endl;" >> $className.cpp
echo "}" >> $className.cpp
echo "" >> $className.cpp
echo "$className::$className($className &other) {" >> $className.cpp
echo "}" >> $className.cpp
echo "$className::~$className() {" >> $className.cpp
echo "  std::cout << \"$className destructor was called.\" << std::endl;" >> $className.cpp
echo "}" >> $className.cpp
echo "" >> $className.cpp
echo "$className &$className::operator=($className &other) {" >> $className.cpp
echo "	if (this != &other){
		
	}
	return *this;" >> $className.cpp
echo "}" >> $className.cpp

echo "Created $className.cpp"