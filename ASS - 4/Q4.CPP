#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

string firstNonRepeatingChar(string stream) {
    queue<char> q;
    unordered_map<char, int> count;
    string result = "";

    for (char ch : stream) {
        q.push(ch);
        count[ch]++;

        // Remove characters that appear more than once from front of queue
        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }

        // Get first non-repeating character
        if (q.empty()) {
            result += "-1";
        } else {
            result += q.front();
        }
        result += " ";
    }

    return result;
}

int main() {
    string input;
    
    cout << "Enter string stream: ";
    getline(cin, input);

    // Remove spaces from input for consistency with sample
    string processed = "";
    for (char c : input) {
        if (c != ' ') {
            processed += c;
        }
    }

    cout << "Input: " << input << endl;
    string output = firstNonRepeatingChar(processed);
    cout << "Output: " << output << endl;

    return 0;
}

