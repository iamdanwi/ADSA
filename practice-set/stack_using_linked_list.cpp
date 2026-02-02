#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);

        newNode->next = top;
        top = newNode;

        cout << val << " is inserted at the top of the stack.\n";
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack underflow.\n";
            return;
        }
        Node *temp = top;
        cout << temp->data << " poped from the stack\n";

        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }
        Node *temp = top;
        cout << "Stack elements (top to bottom): ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();

    return 0;
}