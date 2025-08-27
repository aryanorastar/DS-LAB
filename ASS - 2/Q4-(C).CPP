#include <iostream>
#include <string>

// A helper function to check if a character is a vowel.
bool isVowel(char c) {
    c = tolower(c); // Make the check case-insensitive.
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// This function removes vowels and returns the new string.
std::string deleteVowels(const std::string &str) {
    std::string result = ""; // Start with an empty result string.
    
    // Iterate through each character of the input string.
    for (char c : str) {
        // If the character is NOT a vowel, add it to the result.
        if (!isVowel(c)) {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string text = "Data Structures and Algorithms";
    
    std::cout << "Original string: " << text << std::endl;
    
    std::string no_vowels_text = deleteVowels(text);

    std::cout << "String without vowels: " << no_vowels_text << std::endl;

    return 0;
}