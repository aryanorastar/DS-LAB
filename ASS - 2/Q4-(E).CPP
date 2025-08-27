#include <iostream>
#include <cctype> // Required for tolower()

int main() {
    char upper_char = 'Q';
    
    // The tolower() function from <cctype> handles the conversion.
    // It returns the lowercase version if the input is uppercase,
    // otherwise, it returns the character unchanged.
    char lower_char = tolower(upper_char);

    std::cout << "Uppercase character: " << upper_char << std::endl;
    std::cout << "Lowercase character: " << lower_char << std::endl;
    
    char non_upper_char = 'z';
    std::cout << "\nTrying with '" << non_upper_char << "': " << (char)tolower(non_upper_char) << std::endl;

    return 0;
}