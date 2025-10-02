#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtStart(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int val, int pos)
    {
        if (pos == 0)
        {
            insertAtStart(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp; i++)
        {
            temp = temp->next;
        }
        if (!temp)
            return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

int main()
{
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtStart(0);
    list.insertAtPosition(3, 2);
    list.display();
    return 0;
}
