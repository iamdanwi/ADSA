#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    Node *head = nullptr;

public:
    bool isEmpty()
    {
        return head == nullptr;
    }

    void addNode(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (isEmpty())
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insertInMiddle(int val, int pos)
    {
        if (isEmpty())
        {
            addNode(val);
            return;
        }
        int count = 1;
        Node *newNode = new Node(val);
        Node *temp = head;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "null\n";
    }

    ~SinglyLinkedList()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};

int main(int argc, char const *argv[])
{
    SinglyLinkedList ll;
    ll.addNode(110);
    ll.addNode(120);
    ll.addNode(130);
    ll.addNode(140);
    ll.addNode(150);
    ll.insertAtBeginning(1609);
    ll.insertInMiddle(22, 3);
    ll.printList();

    return 0;
}
