#pragma once

#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
private:
    int _Size= 0;

public:
    

    class Node
    {
    public:

        T Value;
        Node* Next;
        Node* Prev;

    };

    Node* head = NULL;
   


    int Size()
    {
        return _Size;
    }

    void InsertAtBeginning(T value) {


        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */
        
       

        Node* newNode = new Node();
        newNode->Value = value;
        newNode->Next = head;
        newNode->Prev = NULL;

        if (head != NULL) {
            head->Prev = newNode;
        }
        head = newNode;
        _Size++;
    }

    Node* Find(T DataForLooking)
    {
        Node* Current = head;
        while (Current != NULL)
        {
            if (Current->Value == DataForLooking)
                return Current;

            Current = Current->Next;
        }

        return NULL;
    }

    Node* FindLastNode()
    {
        if (head == NULL)
            return NULL;

        Node* Current = head;

        while (Current->Next != NULL)
        {
            Current = Current->Next;
        }

        return Current;
    }

    void InsertAfter(Node*& Current, T value)
    {
        

        Node* new_node = new Node();
        new_node->Value = value;
        new_node->Next = Current->Next;
        new_node->Prev = Current;

        if (Current->Next != NULL)
        {
            Current->Next->Prev = new_node;
        }
        Current->Next = new_node;

        _Size++;
    }

    void InsertAfter(int Index, T Value)
    {
        Node* N = GetNode(Index);

        if (N == NULL)
            return;
        else
            InsertAfter(N, Value);
    }

    void InsertAtEnd(T value)
    {
        

        Node* new_node = new Node();
        new_node->Value = value;
        new_node->Next = NULL;



        if (head == NULL)
        {
            new_node->Prev = NULL;
            head = new_node;
        }
        else
        {
            Node* Current = head;

            while (Current->Next != NULL)
            {
                Current = Current->Next;
            }

            Current->Next = new_node;
            new_node->Prev = Current;
        }

        _Size++;
    }

    void DeleteNode(Node*& NodeToDelete) {

        
        /*
            1-Set the next pointer of the previous node to the next pointer of the current node.
            2-Set the previous pointer of the next node to the previous pointer of the current node.
            3-Delete the current node.
        */
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->Next;
        }
        if (NodeToDelete->Next != NULL) {
            NodeToDelete->Next->Prev = NodeToDelete->Prev;
        }
        if (NodeToDelete->Prev != NULL) {
            NodeToDelete->Prev->Next = NodeToDelete->Next;
        }

        delete NodeToDelete;
        _Size--;
    }

    void DeleteFirstNode() {

        
        /*
            1-Store a reference to the head node in a temporary variable.
            2-Update the head pointer to point to the next node in the list.
            3-Set the previous pointer of the new head to NULL.
            4-Delete the temporary reference to the old head node.
        */

        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->Next;
        if (head != NULL) {
            head->Prev = NULL;
        }
        delete temp;
        _Size--;
    }

    void DeleteLastNode()
    {
        _Size--;

        if (head == NULL)
        {
            return;
        }

        if (head->Next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* Current = head;

        while (Current->Next->Next != NULL)
        {
            Current = Current->Next;
        }

        Node* temp = Current->Next;
        Current->Next = NULL;
        delete temp;
    }

    void PrintList()

    {
        Node* Current = head;
        while (Current != NULL)
        {
            cout << Current->Value << " ";
            Current = Current->Next;
        }
        cout << "\n";
        delete Current;

    }
    
    bool IsEmpty()
    {
        return _Size == 0;
    }

    void Clear()
    {
       
        while (_Size > 0)
        {
            DeleteLastNode();
        }
        
    }

    void  Reverse()
    {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->Prev;
            current->Prev = current->Next;
            current->Next = temp;
            current = current->Prev;
        }

        if (temp != nullptr) {
            head = temp->Prev;
        }
    }

    Node* GetNode(int Index)
    {
        Node* Current = head;

        if (Index > _Size - 1 || Index < 0)
            return NULL;

        int Counter = 0;
        while (Current != NULL && Current->Next != NULL)
        {
            if (Counter == Index)
            {
                break;
            }
            Current = Current->Next;
            Counter++;
        }

        return Current;
    }

    T GetItem(int Index)
    {
        Node* Result = GetNode(Index);

        if (Result == NULL)
            return NULL;
        else
            return Result->Value;
            
    }

    bool UpdateItem(int Index, T NewValue)
    {
        Node* N = GetNode(Index);
        if (N != NULL)
        {
            N->Value = NewValue;
            return true;
        }
        else
            return false;
    }


};

