#include <iostream>
#include <queue>

int main() {
    std::cout << "--- Stack using Two Queues (Push costly) ---\n";
    std::queue<int> q1, q2;

    std::cout << "Pushing 10...\n";
    q2.push(10);
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    std::swap(q1, q2);

    std::cout << "Pushing 20...\n";
    q2.push(20);
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    std::swap(q1, q2);

    std::cout << "Top of stack is: " << q1.front() << "\n";
    std::cout << "Popping " << q1.front() << "\n";
    q1.pop();
    std::cout << "Top of stack is now: " << q1.front() << "\n";

    std::cout << "\n--- Stack using One Queue ---\n";
    std::queue<int> q;
    
    std::cout << "Pushing 30...\n";
    q.push(30);

    std::cout << "Pushing 40...\n";
    q.push(40);
    for (int i = 0; i < q.size() - 1; i++) {
        q.push(q.front());
        q.pop();
    }

    std::cout << "Top of stack is: " << q.front() << "\n";
    std::cout << "Popping " << q.front() << "\n";
    q.pop();
    std::cout << "Top of stack is now: " << q.front() << "\n";

    return 0;
}
