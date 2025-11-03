#include <iostream>
using namespace std;

struct DNode
{
    int data;
    DNode *prev, *next;
};

DNode *dHead = NULL;

void insertDoubly(int val)
{
    DNode *newNode = new DNode{val, NULL, NULL};
    if (dHead == NULL)
        dHead = newNode;
    else
    {
        DNode *temp = dHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int sizeDoubly()
{
    int count = 0;
    DNode *temp = dHead;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

struct CNode
{
    int data;
    CNode *next;
};

CNode *cHead = NULL;

void insertCircular(int val)
{
    CNode *newNode = new CNode{val, NULL};
    if (cHead == NULL)
    {
        cHead = newNode;
        newNode->next = cHead; 
    }
    else
    {
        CNode *temp = cHead;
        while (temp->next != cHead)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = cHead; 
    }
}

int sizeCircular()
{
    if (cHead == NULL)
        return 0;
    int count = 0;
    CNode *temp = cHead;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != cHead);
    return count;
}


int main()
{
    insertDoubly(10);
    insertDoubly(20);
    insertDoubly(30);


    insertCircular(5);
    insertCircular(15);
    insertCircular(25);
    insertCircular(35);

    cout << "Size of Doubly Linked List = " << sizeDoubly() << endl;
    cout << "Size of Circular Linked List = " << sizeCircular() << endl;

    return 0;
}