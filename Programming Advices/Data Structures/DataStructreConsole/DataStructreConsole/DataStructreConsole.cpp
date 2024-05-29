#include <queue>
#include <iostream>

using namespace std;

class Node
{
public:

    int Value;
    Node* Next;
    Node* Prev;
    
};

void InsertAtBeginning(Node*& head, int value) {


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
}

void PrintNodeDetails(Node* head)
{

    if (head->Prev != NULL)
        cout << head->Prev->Value;
    else
        cout << "NULL";

    cout << " <--> " << head->Value << " <--> ";

    if (head->Next != NULL)
        cout << head->Next->Value << "\n";
    else
        cout << "NULL";

}

void PrintListDetails(Node* head)

{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->Next;
    }
}

void PrintList(Node* head)

{
    cout << "NULL <--> ";
    while (head != NULL) {
        cout << head->Value << " <--> ";
        head = head->Next;
    }
    cout << "NULL";

}

Node* Find(Node* head, int value)
{
    while (head != NULL)
    {

        if (head->Value == value)
            return head;

        head = head->Next;

    }
    return NULL;
}

void InsertAfter(Node*& Current, int value)
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
}

void InsertAtEnd(Node*& head, int value)
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
}

void DeleteNode(Node*& head, Node*& NodeToDelete) {


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
}

void DeleteFirstNode(Node*& head) {

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
}

void DeleteLastNode(Node*& head)
{
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

int main()
{
   


    system("pause>0");

}