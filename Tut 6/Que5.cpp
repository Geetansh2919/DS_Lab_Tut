#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;


void insertEnd(int val)
{
    Node *newNode = new Node{val, NULL};
    if (head == NULL)
        head = newNode;
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void makeCircular()
{
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head; 
}

bool isCircular()
{
    if (head == NULL)
        return false;

    Node *temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;

    if (temp == head)
        return true; 
        else
        return false; 
}


void display()
{
    Node *temp = head;
    cout << "Linked List: ";
    int count = 0; 
    while (temp != NULL && count < 10)
    {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    cout << endl;
}


int main()
{

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    display();

    if (isCircular())
        cout << "The linked list is CIRCULAR.\n";
    else
        cout << "The linked list is NOT circular.\n";

    return 0;
}