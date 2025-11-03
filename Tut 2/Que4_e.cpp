#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    // Convert to lowercase
    if (ch >= 'A' && ch <= 'Z')
        ch = ch + ('a' - 'A');
    cout << "Lowercase character: " << ch << endl;
    return 0;
}
