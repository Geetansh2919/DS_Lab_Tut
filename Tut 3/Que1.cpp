#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
        } else {
            top++;
            arr[top] = x;
            cout << x << " pushed to stack.\n";
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
        } else {
            cout << arr[top] << " popped from stack.\n";
            top--;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\nMenu:\n"
             << "1. Push\n"
             << "2. Pop\n"
             << "3. isEmpty\n"
             << "4. isFull\n"
             << "5. Display\n"
             << "6. Peek\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                if (s.isEmpty()) cout << "Stack is empty.\n";
                else cout << "Stack is not empty.\n";
                break;

            case 4:
                if (s.isFull()) cout << "Stack is full.\n";
                else cout << "Stack is not full.\n";
                break;

            case 5:
                s.display();
                break;

            case 6:
                s.peek();
                break;

            case 7:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
