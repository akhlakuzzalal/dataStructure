#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node(int val)
    {
        value = val;
        Next = NULL;
    }
};

void display(Node *head);
int countListSize(Node *&head);
void insertAtTail(Node *&head, int val);
void insertAtHead(Node *&head, int value);
void insertAtMidle(Node *&head, int pos, int val);
int searchValue(Node *&head, int value);
void deleteAtHead(Node *&head);
void deleteAtTail(Node *&head);
void deleteAtSpecificposition(Node *&head, int pos);
void searchValueAndDelete(Node *&head, int value);
Node *nonRecursiveReverse(Node *&head);
Node *recursiveReverse(Node *&head);

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->Next;
    }
    cout << endl;
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
        temp->Next = newNode;
    }
};

void insertAtHead(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->Next = head;
    head = newNode;
}

void insertAtMidle(Node *&head, int pos, int val)
{
    int size = countListSize(head);
    if (pos > size)
    {
        cout << "possition is not available" << endl;
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->Next;
        count++;
    }
    newNode->Next = temp->Next;
    temp->Next = newNode;
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

int searchValue(Node *&head, int value)
{
    if (head == NULL)
    {
        return -1;
    }
    Node *temp = head;
    int pos = 1;
    while (temp->value != value)
    {
        if (temp->Next == NULL)
        {
            return -1;
        }
        pos++;
        temp = temp->Next;
    }
    return pos;
}

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
    }
    else
    {
        head = temp->Next;
        delete temp;
    }
}

void deleteAtTail(Node *&head)
{
    Node *temp = head;
    if (temp != NULL && temp->Next != NULL)
    {
        while (temp->Next->Next != NULL)
        {
            temp = temp->Next;
        }
        Node *deleteNode = temp->Next;
        temp->Next = NULL;
        delete temp->Next;
    }
    else
    {
        if (temp == NULL)
        {
            cout << "Linked List is Empty" << endl;
        }
        else
            deleteAtHead(head);
    }
}

void deleteAtSpecificposition(Node *&head, int pos)
{
    Node *temp = head;
    int i = 1;
    if (pos == countListSize(head))
    {
        deleteAtTail(head);
        return;
    }
    else if (temp != NULL && pos <= countListSize(head) && pos > 0)
    {
        while (pos - 1 > i)
        {
            temp = temp->Next;
            i++;
        }
        Node *DeleteNode = temp->Next;
        temp->Next = DeleteNode->Next;
        delete DeleteNode;
    }
    else
    {
        if (head == NULL)
        {
            cout << "List Underflow" << endl;
        }
        else if (pos > countListSize(head) || pos < 0)
        {
            cout << "Position not valid" << endl;
        }
        else if (pos == 1)
        {
            deleteAtHead(head);
        }
    }
};

void searchValueAndDelete(Node *&head, int value)
{
    int pos = searchValue(head, value);
    if (pos == -1)
    {
        cout << "The value is not present now" << endl;
    }
    else
        deleteAtSpecificposition(head, pos);
}

Node *nonRecursiveReverse(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    if (current == NULL)
    {
        cout << "No element in the list" << endl;
        ;
        return head;
    }
    Node *next = current->Next;
    while (true)
    {
        current->Next = prev;
        prev = current;
        current = next;
        if (current == NULL)
            break;
        next = next->Next;
    }
    return prev;
}

Node *recursiveReverse(Node *&head)
{
    if (head == NULL || head->Next == NULL)
    {
        return head;
    }
    Node *newHead = recursiveReverse(head->Next);
    head->Next->Next = head;
    head->Next = NULL;
    return newHead;
}

int main()
{
    Node *head = NULL;
    int choice;
    cout << "Choice 1: insert at tail" << endl;
    cout << "Choice 2: insert at head" << endl;
    cout << "Choice 3: insert at midle" << endl;
    cout << "Choice 4: list size" << endl;
    cout << "Choice 5: search a value from list" << endl;
    cout << "Choice 6: delete at head" << endl;
    cout << "Choice 7: delete at tail" << endl;
    cout << "Choice 8: display list" << endl;
    cout << "Choice 9: delete at specific position" << endl;
    cout << "Choice 10: delete with value" << endl;
    cout << "Choice 11: reverse list nonRecursive" << endl;
    cout << "Choice 11: reverse list Recursive" << endl;
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
            cout << "Possition: ";
            cin >> position;
            cout << "Value: ";
            cin >> n;
            insertAtMidle(head, position, n);
            break;
        case 4:
            cout << "List Size: " << countListSize(head) << endl;
            break;
        case 5:
            cout << "Search Value: ";
            cin >> n;
            position = searchValue(head, n);
            if (position == -1)
                cout << "NOT FOUND" << endl;
            else
                cout << "Found at: " << position << endl;
            break;
        case 6:
            deleteAtHead(head);
            break;
        case 7:
            deleteAtTail(head);
            break;
        case 8:
            display(head);
            break;
        case 9:
            cout << "Possition: ";
            cin >> position;
            deleteAtSpecificposition(head, position);
            break;
        case 10:
            cout << "value for delete: ";
            cin >> n;
            searchValueAndDelete(head, n);
            break;
        case 11:
            head = nonRecursiveReverse(head);
            break;
        case 12:
            head = recursiveReverse(head);
            break;
        default:
            break;
        }
        cout << "Next Choice: ";
        cin >> choice;
    }

    return 0;
}