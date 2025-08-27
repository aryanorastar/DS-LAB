#include <iostream>
#include <string>
#include <stack>   // Required for using the std::stack container

/**
 * @brief Reverses a string using a character stack.
 * @param inputStr The original string to be reversed.
 * @return The reversed string.
 */
std::string reverseStringWithStack(const std::string& inputStr) {
    // Create a stack to hold the characters of the string.
    std::stack<char> charStack;

    // Phase 1: Push every character from the input string onto the stack.
    for (char c : inputStr) {
        charStack.push(c);
    }

    // Create an empty string to build the reversed version.
    std::string reversedStr;
    // Pre-allocating memory can be a small optimization.
    reversedStr.reserve(inputStr.length()); 

    // Phase 2: Pop characters from the stack and append them to the result.
    while (!charStack.empty()) {
        // Get the top character.
        reversedStr += charStack.top(); 
        // Remove the top character.
        charStack.pop();
    }

    return reversedStr;
}

int main() {
    std::string original = "DataStructure";
    std::cout << "Original String: " << original << std::endl;

    std::string reversed = reverseStringWithStack(original);
    
    std::cout << "Reversed String: " << reversed << std::endl; // Expected: erutcurtSataD

    return 0;
}