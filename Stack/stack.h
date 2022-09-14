#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
public:
    T value;
    Node *Next;
    Node *Prev;
    Node(T value)
    {
        this->value = value;
        this->Next = NULL;
        this->Prev = NULL;
    }
};

template <typename S>
class Stack
{
    Node<S> *head = NULL;
    Node<S> *top = NULL;
    int count = 0;

public:
    //  Push
    void push(S value)
    {
        Node<S> *newNode = new Node<S>(value);
        if (head == NULL)
        {
            head = newNode;
            top = newNode;
            count++;
            return;
        }
        top->Next = newNode;
        newNode->Prev = top;
        top = newNode;
        count++;
    }
    //  Pop
    S pop()
    {
        S chk;
        Node<S> *delNode = top;
        if (head == NULL)
        {
            return chk;
        }
        if (top == head)
        {
            top = NULL;
            head = NULL;
        }
        else
        {
            top = delNode->Prev;
            top->Next = NULL;
        }
        chk = delNode->value;
        delete delNode;
        count--;
        return chk;
    }
    //  Size
    int size()
    {
        return count;
    }
    //  isEmpty
    bool isEmpty()
    {
        if (head != NULL)
            return false;
        else
            return true;
    }
    //  Top
    S Top()
    {
        S chk;
        if (head == NULL)
        {
            return chk;
        }
        else
            chk = top->value;
        return top->value;
    }
};