#include <iostream>
#include <string>
#include <utility> // For std::swap

// This function reverses the string directly (in-place).
void reverseString(std::string &str) {
    int left = 0;
    int right = str.length() - 1;

    // Use a two-pointer approach to swap characters.
    while (left < right) {
        std::swap(str[left], str[right]);
        left++;
        right--;
    }
}

int main() {
    std::string text = "Hello World";
    
    std::cout << "Original string: " << text << std::endl;
    
    reverseString(text);

    std::cout << "Reversed string: " << text << std::endl;

    return 0;
}