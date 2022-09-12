#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int value)
    {
        this->value = value;
        this->Next = NULL;
    }
};

void insertAtHead(Node *&head, int val);
void insertAtTail(Node *&head, int val);
int listSize(Node *&head);
void deleteAtHead(Node *&head);
void deleteAtTail(Node *head);
void display(Node *head);

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }
    Node *temp = head;
    newNode->Next = head;
    do
    {
        temp = temp->Next;
    } while (temp->Next != head);
    temp->Next = newNode;
    head = newNode;
}

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        newNode->Next = head;
        return;
    }
    Node *temp = head;
    do
    {
        temp = temp->Next;
    } while (temp->Next != head);
    temp->Next = newNode;
    newNode->Next = head;
}

int listSize(Node *&head)
{
    if (head == NULL)
    {
        return 0;
    }
    Node *temp = head;
    int count = 0;
    do
    {
        temp = temp->Next;
        count++;
    } while (temp != head);
    return count;
}

void deleteAtHead(Node *&head)
{
    if (head != NULL)
    {
        Node *delNode = head;
        Node *temp = head;
        do
        {
            temp = temp->Next;
        } while (temp->Next != head);
        if (delNode == temp)
            head = NULL;
        else
        {
            temp->Next = delNode->Next;
            head = delNode->Next;
            delete delNode;
        }
    }
    else
    {
        cout << "Nothing in the List" << endl;
    }
}

void deleteAtTail(Node *head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next->Next != head)
    {
        while (temp->Next->Next != head)
        {
            temp = temp->Next;
        }
        Node *delNode = temp->Next;

        temp->Next = delNode->Next;
        delete delNode;
    }
    else
    {
        if (temp == NULL)
        {
            cout << "Nothing in the list" << endl;
        }
        else
        {
            deleteAtHead(head);
        }
    }
}

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "Linkedlist is empty" << endl;
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->value << " ";
        temp = temp->Next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int choice;
    int value;
    cout << "Choice 1: insert at head" << endl;
    cout << "Choice 2: insert at tail" << endl;
    cout << "Choice 3: list size" << endl;
    cout << "Choice 4: delete at head" << endl;
    cout << "Choice 5: delete at tail" << endl;
    cout << "Choice 6: display list" << endl;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "insert a value: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "insert a value: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            int size;
            size = listSize(head);
            cout << "List size is :" << size << endl;
            break;
        case 4:
            deleteAtHead(head);
            break;
        case 5:
            deleteAtTail(head);
            break;
        case 6:
            display(head);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }

    return 0;
}