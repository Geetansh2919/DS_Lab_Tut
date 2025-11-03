#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getPrecedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string convertToPostfix(string expression) {
    stack<char> my_stack;
    string result = "";

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            result += ch;
        } else if (ch == '(') {
            my_stack.push('(');
        } else if (ch == ')') {
            while (my_stack.top() != '(') {
                result += my_stack.top();
                my_stack.pop();
            }
            my_stack.pop();
        } else {
            while (!my_stack.empty() && getPrecedence(ch) <= getPrecedence(my_stack.top())) {
                result += my_stack.top();
                my_stack.pop();
            }
            my_stack.push(ch);
        }
    }

    while (!my_stack.empty()) {
        result += my_stack.top();
        my_stack.pop();
    }

    return result;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix_result;
    postfix_result = convertToPostfix(infix);

    cout << "The postfix expression is: " << postfix_result << endl;

    return 0;
}
