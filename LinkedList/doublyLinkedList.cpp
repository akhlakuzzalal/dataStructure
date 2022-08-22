#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node *Prev;
    Node(int val)
    {
        value = val;
        Next = NULL;
        Prev = NULL;
    }
};
void display(Node *head);
int countListSize(Node *&head);
void insertAtHead(Node *&head, int value);
void insertAtTail(Node *&head, int val);
void reversePrint(Node *&head);

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->Next;
    }
    cout << endl;
}

int countListSize(Node *&head)
{
    int count = 1;
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
        count++;
    }
    return count;
}

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->Next = head;
    head->Prev = newNode;
    head = newNode;
}

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
    }

    else
    {
        Node *temp = head;
        while (temp->Next != NULL)
        {
            temp = temp->Next;
        }
        newNode->Prev = temp;
        temp->Next = newNode;
    }
};

void reversePrint(Node *&head)
{
    Node *temp = head;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
    }
    Node *newHead = temp;
    while (newHead != NULL)
    {
        cout << newHead->value << " ";
        newHead = newHead->Prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int choice;
    cout << "Choice 1: insert at tail" << endl;
    cout << "Choice 2: insert at head" << endl;
    cout << "Choice 3: print list" << endl;
    cout << "Choice 4: reverse print list" << endl;
    while (choice != 0)
    {
        int n;
        int position;
        switch (choice)
        {
        case 1:
            cout << "Value: ";
            cin >> n;
            insertAtTail(head, n);
            break;
        case 2:
            cout << "Value: ";
            cin >> n;
            insertAtHead(head, n);
            break;
        case 3:
            display(head);
            break;
        case 4:
            reversePrint(head);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }
    return 0;
}