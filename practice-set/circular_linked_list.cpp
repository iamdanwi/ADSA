#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *tail = nullptr; // tail->next is head

public:
    bool isEmpty()
    {
        return tail == nullptr;
    }

    // Insert at end (O(1))
    void insert(int val)
    {
        Node *newNode = new Node(val);

        if (isEmpty())
        {
            tail = newNode;
            tail->next = tail; // points to itself
            return;
        }

        newNode->next = tail->next; // new -> head
        tail->next = newNode;       // old tail -> new
        tail = newNode;             // update tail
    }

    // Insert at beginning (O(1))
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);

        if (isEmpty())
        {
            tail = newNode;
            tail->next = tail;
            return;
        }

        newNode->next = tail->next;
        tail->next = newNode;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = tail->next; // head
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);

        cout << "(back to head)\n";
    }

    bool hasCycle()
    {
        if (isEmpty())
            return false;

        Node *head = tail->next;
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }

    ~CircularLinkedList()
    {
        if (isEmpty())
            return;

        Node *curr = tail->next; // head

        while (curr != tail)
        {
            Node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }

        delete tail; // delete last node
        tail = nullptr;
    }
};

int main()
{
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insertAtBeginning(5);
    cll.print();
    if (cll.hasCycle())
    {
        cout << "CLL has a cycle.\n";
    }

    return 0;
}
