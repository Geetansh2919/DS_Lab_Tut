#include <iostream>

int main() {
    int cqueue[5];
    int size = 5;
    int front = -1;
    int rear = -1;
    int choice;

    std::cout << "--- Circular Queue Program ---\n";

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Display\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
                std::cout << "Queue is full.\n";
            } else {
                int val;
                std::cout << "Enter value: ";
                std::cin >> val;
                if (front == -1) front = 0;
                rear = (rear + 1) % size;
                cqueue[rear] = val;
            }
        } else if (choice == 2) {
            if (front == -1) {
                std::cout << "Queue is empty.\n";
            } else {
                std::cout << "Dequeued " << cqueue[front] << "\n";
                if (front == rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front = (front + 1) % size;
                }
            }
        } else if (choice == 3) {
            if (front == -1) {
                std::cout << "Queue is empty.\n";
            } else {
                std::cout << "Queue: ";
                if (rear >= front) {
                    for (int i = front; i <= rear; i++)
                        std::cout << cqueue[i] << " ";
                } else {
                    for (int i = front; i < size; i++)
                        std::cout << cqueue[i] << " ";
                    for (int i = 0; i <= rear; i++)
                        std::cout << cqueue[i] << " ";
                }
                std::cout << "\n";
            }
        }
    } while (choice != 4);
    
    return 0;
}
