#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, result;
    cout << "Enter a string: ";
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        char c = tolower(str[i]);
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
            result += str[i];
    }
    cout << "String without vowels: " << result << endl;
    return 0;
}
