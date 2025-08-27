#include <iostream>
#include <string>
#include <stack>
#include <cmath>   // For the pow() function used in exponentiation
#include <cctype>  // For the isdigit() function

/**
 * @brief Evaluates a postfix expression (with single-digit numbers).
 * @param postfix The postfix expression string.
 * @return The integer result of the evaluation.
 */
int evaluatePostfix(const std::string& postfix) {
    // We use a stack of integers to hold the operands.
    std::stack<int> operandStack;

    // Scan the expression from left to right.
    for (char ch : postfix) {
        // Case 1: If the character is a digit (an operand)...
        if (isdigit(ch)) {
            // ...convert it from a character to an integer and push it onto the stack.
            // ('5' - '0' results in the integer 5)
            operandStack.push(ch - '0');
        }
        // Case 2: If the character is an operator...
        else {
            // ...we need to operate on the top two operands.
            // Important: The first element popped is the second operand.
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            // Perform the correct operation.
            switch (ch) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
                case '^':
                    operandStack.push(pow(operand1, operand2));
                    break;
            }
        }
    }

    // The final result is the only number left on the stack.
    return operandStack.top();
}

int main() {
    std::string postfix_expr = "231*+9-";
    
    std::cout << "Postfix Expression: " << postfix_expr << std::endl;
    
    int result = evaluatePostfix(postfix_expr);
    
    std::cout << "Result: " << result << std::endl; // Expected: (2 + (3 * 1)) - 9 = -4

    return 0;
}