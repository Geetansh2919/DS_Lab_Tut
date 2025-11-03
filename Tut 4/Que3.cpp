#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    std::cout << "--- Interleave Queue Program ---\n";
    std::cout << "Original queue: 4 7 11 20 5 9\n";

    std::stack<int> s;
    int half = q.size() / 2;

    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }

    std::cout << "Interleaved queue: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";

    return 0;
}
