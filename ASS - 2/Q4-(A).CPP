#include <iostream>
#include <string>

int main() {
    // Using the std::string class for modern C++ string handling.
    std::string first_part = "Data ";
    std::string second_part = "Structures";

    // The '+' operator is overloaded for std::string to handle concatenation.
    std::string combined = first_part + second_part;

    std::cout << "First string: " << first_part << std::endl;
    std::cout << "Second string: " << second_part << std::endl;
    std::cout << "Combined string: " << combined << std::endl;

    return 0;
}