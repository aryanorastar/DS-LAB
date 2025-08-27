#include <iostream>
#include <string>
#include <stack>
#include <cctype> // For isalnum()

/**
 * @brief Determines the precedence of a mathematical operator.
 * Higher number means higher precedence.
 * @param op The operator character.
 * @return An integer representing its precedence level.
 */
int getPrecedence(char op) {
    if (op == '^')
        return 3; // Exponentiation has the highest precedence
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0; // For parentheses
}

/**
 * @brief Converts an infix expression string to a postfix expression string.
 * @param infix The infix expression.
 * @return The resulting postfix expression.
 */
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operatorStack;
    std::string postfix;

    for (char ch : infix) {
        // Case 1: If the character is an operand (letter or digit), add it to the result.
        if (isalnum(ch)) {
            postfix += ch;
        }
        // Case 2: If the character is an opening parenthesis, push it onto the stack.
        else if (ch == '(') {
            operatorStack.push(ch);
        }
        // Case 3: If the character is a closing parenthesis...
        else if (ch == ')') {
            // ...pop from the stack to the result until an opening parenthesis is found.
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty()) {
                operatorStack.pop(); // Pop and discard the '('
            }
        }
        // Case 4: If the character is an operator.
        else {
            // Pop operators from the stack that have higher or equal precedence.
            // Note: '^' is right-associative, so we only pop if precedence is strictly greater.
            while (!operatorStack.empty() && operatorStack.top() != '(' &&
                   (getPrecedence(operatorStack.top()) > getPrecedence(ch) ||
                   (getPrecedence(operatorStack.top()) == getPrecedence(ch) && ch != '^'))) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            // Push the current operator onto the stack.
            operatorStack.push(ch);
        }
    }

    // After the loop, pop any remaining operators from the stack to the result.
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string infix_expr = "A+B*(C^D-E)^(F+G*H)-I";
    
    std::cout << "Infix Expression:   " << infix_expr << std::endl;
    
    std::string postfix_expr = infixToPostfix(infix_expr);
    
    std::cout << "Postfix Expression: " << postfix_expr << std::endl;
    // Expected: ABCD^E-FGH*+^*+I-

    return 0;
}