#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    stack<char> st;

    for (char c : str) {
        st.push(c);
    }
    
    string reversedStr = "";
    while (!st.empty()) {
        reversedStr += st.top();
        st.pop();
    }

    cout << "Reversed string: " << reversedStr << endl;

    return 0;
}
