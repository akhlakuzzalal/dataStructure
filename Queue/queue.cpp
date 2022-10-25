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

class Queue
{
    Node *Front;
    Node *Back;

public:
    Queue()
    {
        Front = NULL;
        Back = NULL;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        if (Front == NULL && Back == NULL)
        {
            Front = newNode;
            Back = newNode;
            return;
        }
        Back->Next = newNode;
        Back = newNode;
    }

    int pop()
    {
        Node *delNode = Front;
        int chk = -1;
        if (Front == NULL)
        {
            Back = NULL;
        }
        Front = Front->Next;
        chk = delNode->value;
        delete delNode;
        return chk;
    }

    int front()
    {
        if (Front == NULL)
        {
            return -1;
        }
        return Front->value;
    }

    int back()
    {
        if (Front == NULL)
        {
            return -1;
        }
        else
            return Back->value;
    }

    bool isEmpty()
    {
        if (Front == NULL && Back == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    Queue q;
    cout << q.isEmpty() << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.isEmpty() << endl;

    while (!q.isEmpty())
    {
        cout << q.pop() << " ";
    }
    cout << q.front() << endl;
    cout << q.back() << endl;

    return 0;
}