#include <iostream>
#include <string>
#include <stack>

/**
 * @brief Checks if an expression has balanced parentheses.
 * @param expression The string containing the expression.
 * @return True if parentheses are balanced, otherwise false.
 */
bool areParenthesesBalanced(const std::string& expression) {
    std::stack<char> s;

    // Iterate through each character in the expression.
    for (char ch : expression) {
        // If it's an opening bracket, push it onto the stack.
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If it's a closing bracket, check for a match.
        else if (ch == ')' || ch == '}' || ch == ']') {
            // Unbalanced Case 1: A closing bracket appears but the stack is empty.
            if (s.empty()) {
                return false;
            }

            // Get the last-opened bracket from the top of the stack.
            char top = s.top();
            s.pop();

            // Unbalanced Case 2: The closing bracket does not match the last-opened one.
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // Unbalanced Case 3: After checking all characters, the stack is not empty,
    // meaning there are unclosed opening brackets left over.
    return s.empty();
}

int main() {
    std::string expr1 = "{[a + b] * (c - d)}";
    std::string expr2 = "((a+b) * c"; // Unclosed bracket
    std::string expr3 = "{(a+b])";    // Mismatched brackets
    std::string expr4 = "a+b)";       // Closing bracket first

    std::cout << "Expression: " << expr1 << "\nResult: "
              << (areParenthesesBalanced(expr1) ? "✅ Balanced" : "❌ Not Balanced") << std::endl;

    std::cout << "\nExpression: " << expr2 << "\nResult: "
              << (areParenthesesBalanced(expr2) ? "✅ Balanced" : "❌ Not Balanced") << std::endl;

    std::cout << "\nExpression: " << expr3 << "\nResult: "
              << (areParenthesesBalanced(expr3) ? "✅ Balanced" : "❌ Not Balanced") << std::endl;

    std::cout << "\nExpression: " << expr4 << "\nResult: "
              << (areParenthesesBalanced(expr4) ? "✅ Balanced" : "❌ Not Balanced") << std::endl;

    return 0;
}