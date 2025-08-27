#include <iostream>
#include <string>
#include <algorithm> // Required for std::sort

int main() {
    std::string text = "datastructures";
    
    std::cout << "Original string: " << text << std::endl;
    
    // The std::sort function can work directly on strings.
    std::sort(text.begin(), text.end());

    std::cout << "Sorted string:   " << text << std::endl;

    return 0;
}