#include <iostream>

int main() {
    int queue[10];
    int size = 10;
    int front = -1;
    int rear = -1;
    int choice;

    std::cout << "--- Simple Queue Program ---\n";

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add (Enqueue)\n";
        std::cout << "2. Remove (Dequeue)\n";
        std::cout << "3. Show front (Peek)\n";
        std::cout << "4. Display Queue\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            if (rear == size - 1) {
                std::cout << "Error: Queue is full.\n";
            } else {
                int val;
                std::cout << "Enter a number to add: ";
                std::cin >> val;
                if (front == -1) {
                    front = 0;
                }
                rear = rear + 1;
                queue[rear] = val;
                std::cout << val << " was added.\n";
            }
        } else if (choice == 2) {
            if (front == -1 || front > rear) {
                std::cout << "Error: Queue is empty.\n";
            } else {
                std::cout << "Removed " << queue[front] << " from queue.\n";
                front = front + 1;
            }
        } else if (choice == 3) {
            if (front == -1 || front > rear) {
                std::cout << "Error: Queue is empty.\n";
            } else {
                std::cout << "Front element is: " << queue[front] << "\n";
            }
        } else if (choice == 4) {
            if (front == -1 || front > rear) {
                std::cout << "Queue is empty.\n";
            } else {
                std::cout << "Queue elements are: ";
                for (int i = front; i <= rear; i++) {
                    std::cout << queue[i] << " ";
                }
                std::cout << "\n";
            }
        } else if (choice == 5) {
            break;
        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
