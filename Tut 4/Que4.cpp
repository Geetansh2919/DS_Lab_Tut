#include <iostream>
#include <queue>
#include <string>

int main() {
    std::string str = "aabc";
    int freq[26] = {0};
    std::queue<char> q;

    std::cout << "--- First Non-Repeating Character Program ---\n";
    std::cout << "Input: " << str << "\n";
    std::cout << "Output: ";

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);

        while (!q.empty()) {
            if (freq[q.front() - 'a'] > 1) {
                q.pop();
            } else {
                std::cout << q.front() << " ";
                break;
            }
        }
        if (q.empty()) {
            std::cout << "-1 ";
        }
    }
    std::cout << "\n";
    return 0;
}
