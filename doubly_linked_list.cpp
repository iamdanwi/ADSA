#include <iostream>

class Node
{
private:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
    friend class DoublyLinkedList;
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPosition(int data, int position)
    {
        if (position < 0)
            return;
        if (position == 0)
        {
            insertAtBeginning(data);
            return;
        }

        Node *newNode = new Node(data);
        Node *current = head;
        for (int i = 0; i < position - 1 && current; i++)
        {
            current = current->next;
        }

        if (!current)
        {
            insertAtEnd(data);
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next)
            current->next->prev = newNode;
        current->next = newNode;
        if (!newNode->next)
            tail = newNode;
    }

    void deleteFromBeginning()
    {
        if (!head)
            return;

        Node *temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
    }

    void deleteFromEnd()
    {
        if (!head)
            return;

        Node *temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
    }

    void deleteFromPosition(int position)
    {
        if (!head || position < 0)
            return;
        if (position == 0)
        {
            deleteFromBeginning();
            return;
        }

        Node *current = head;
        for (int i = 0; i < position && current; i++)
        {
            current = current->next;
        }

        if (!current)
            return;

        if (current == tail)
        {
            deleteFromEnd();
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    Node *search(int value)
    {
        Node *current = head;
        while (current)
        {
            if (current->data == value)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    int countNodes()
    {
        int count = 0;
        Node *current = head;
        while (current)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    void reverse()
    {
        Node *current = head;
        Node *temp = nullptr;

        while (current)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp)
        {
            tail = head;
            head = temp->prev;
        }
    }

    void clear()
    {
        while (head)
        {
            deleteFromBeginning();
        }
    }

    void display()
    {
        Node *current = head;
        while (current)
        {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void displayReverse()
    {
        Node *current = tail;
        while (current)
        {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main()
{
    DoublyLinkedList dll;

    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtBeginning(0);
    dll.insertAtEnd(3);

    std::cout << "Forward traversal: ";
    dll.display();

    std::cout << "Reverse traversal: ";
    dll.displayReverse();

    dll.deleteFromBeginning();
    dll.deleteFromEnd();

    std::cout << "After deletions: ";
    dll.display();

    dll.insertAtPosition(4, 1);
    std::cout << "After inserting 4 at position 1: ";
    dll.display();

    dll.deleteFromPosition(1);
    std::cout << "After deleting from position 1: ";
    dll.display();

    if (dll.search(2))
        std::cout << "Found 2" << std::endl;

    std::cout << "Node count: " << dll.countNodes() << std::endl;

    dll.reverse();
    std::cout << "After reversal: ";
    dll.display();

    dll.clear();
    std::cout << "After clearing the list: ";
    dll.display();

    return 0;
}