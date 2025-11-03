#include <iostream>
#include <stack>
using namespace std;

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int main() {
    string expr;
    stack<char> s;

    cout << "Enter the expression: ";
    getline(cin, expr);

    int balanced = 1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                balanced = 0;
                break;
            } else if (isMatchingPair(s.top(), ch) == 0) {
                balanced = 0;
                break;
            } else {
                s.pop();
            }
        }
    }

    if (balanced == 1 && s.empty()) {
        cout << "The expression has balanced parentheses.\n";
    } else {
        cout << "The expression does NOT have balanced parentheses.\n";
    }

    return 0;
}
