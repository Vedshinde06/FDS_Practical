#include<iostream>
using namespace std;

class SinglyLinkedList
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    void insertAtStart(int item);
    void insertAtEnd(int item);
    void insertAtPosition(int item, int position);
    void removeAtStart();
    void removeAtEnd();
    void removeByKey(int key);
    void printList();
};

void SinglyLinkedList::insertAtStart(int item)
{
    Node* newNode = new Node();
    newNode->data = item;
    newNode->next = head;
    head = newNode;
}

void SinglyLinkedList::insertAtEnd(int item)
{
    Node* newNode = new Node();
    newNode->data = item;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void SinglyLinkedList::insertAtPosition(int item, int position)
{
    if (position <= 0)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* newNode = new Node();
    newNode->data = item;

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == nullptr)
        {
            cout << "Position out of range!" << endl;
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void SinglyLinkedList::removeAtStart()
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void SinglyLinkedList::removeAtEnd()
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void SinglyLinkedList::removeByKey(int key)
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->data == key)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != key)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        cout << "Key not found!" << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void SinglyLinkedList::printList()
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    SinglyLinkedList list;
    int choice, item, position;

    do
    {
        cout << "\n**** Singly Linked List Operations ****\n";
        cout << "1. Insert at start\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Remove at start\n";
        cout << "5. Remove at end\n";
        cout << "6. Remove by key\n";
        cout << "7. Print list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert at start: ";
            cin >> item;
            list.insertAtStart(item);
            break;

        case 2:
            cout << "Enter the value to insert at end: ";
            cin >> item;
            list.insertAtEnd(item);
            break;

        case 3:
            cout << "Enter the value to insert: ";
            cin >> item;
            cout << "Enter the position: ";
            cin >> position;
            list.insertAtPosition(item, position);
            break;

        case 4:
            list.removeAtStart();
            break;

        case 5:
            list.removeAtEnd();
            break;

        case 6:
            cout << "Enter the key to remove: ";
            cin >> item;
            list.removeByKey(item);
            break;

        case 7:
            list.printList();
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 8);

    return 0;
}