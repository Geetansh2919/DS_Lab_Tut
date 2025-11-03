#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string expression;
    stack<int> s;

    cout << "Enter a postfix expression to evaluate: ";
    cin >> expression;

    for (int i = 0; i < expression.length(); i++) {
        char character = expression[i];

        if (character >= '0' && character <= '9') {
            s.push(character - '0');
        } else {
            int operand2 = s.top();
            s.pop();

            int operand1 = s.top();
            s.pop();
            
            int result;

            if (character == '+') {
                result = operand1 + operand2;
                s.push(result);
            } else if (character == '-') {
                result = operand1 - operand2;
                s.push(result);
            } else if (character == '*') {
                result = operand1 * operand2;
                s.push(result);
            } else if (character == '/') {
                result = operand1 / operand2;
                s.push(result);
            }
        }
    }

    cout << "The result is: " << s.top() << endl;

    return 0;
}
