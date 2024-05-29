#pragma once
#include <iostream>

using namespace std;

class Node
{
public:

    int Value;
    Node* Next;


};

void InsertAtBeginning(Node*& head, int Value)
{
    Node* NewNode = NULL;
    NewNode = new Node();

    NewNode->Value = Value;
    NewNode->Next = head;
    head = NewNode;
}

Node* Find(Node* Head, int DataForLooking)
{
    while (Head != NULL)
    {
        if (Head->Value == DataForLooking)
            return Head;

        Head = Head->Next;
    }

    return NULL;
}

void InsertAfter(Node* previousNode, int value)
{
    if (previousNode == NULL)
    {
        cout << "\nThe gavin previous node can't be null";
        return;
    }

    Node* newNode = new Node();


    newNode->Value = value;
    newNode->Next = previousNode->Next;

    previousNode->Next = newNode;


}

void PrintLinkedList(Node* head)
{
    while (head != NULL)
    {
        cout << head->Value << " ";
        head = head->Next;
    }

}

void PrintNode(Node* node)
{
    cout << node->Value;
}

void InsertAtEnd(Node*& head, int value)
{

    Node* new_node = new Node();

    new_node->Value = value;
    new_node->Next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    Node* LastNode = head;


    while (LastNode->Next != NULL)
    {
        LastNode = LastNode->Next;
    }


    LastNode->Next = new_node;
    return;
}

void DeleteNode(Node*& head, int value)
{
    Node* Current = head, * Prev = head;

    if (head == NULL)
    {
        return;
    }

    if (Current->Value == value)
    {
        head = Current->Next;
        delete Current;
        return;
    }

    while (Current != NULL && Current->Value != value)
    {
        Prev = Current;
        Current = Current->Next;
    }

    if (Current == NULL)return;

    Prev->Next = Current->Next;
    delete Current;



}

void DeleteFirstNode(Node*& head)
{
    Node* Current = head;

    if (head == NULL)
    {
        return;
    }

    head = Current->Next;
    delete Current;
    return;

}

void DeleteLastNode(Node*& head)
{
    Node* Current = head, * Prev = head;

    if (head == NULL)
        return;

    if (Current->Next == NULL)
    {
        head == NULL;
        delete Current;
        return;
    }

    while (Current != NULL && Current->Next != NULL)
    {
        Prev = Current;
        Current = Current->Next;
    }

    Prev->Next = NULL;
    delete Current;
    return;

}
