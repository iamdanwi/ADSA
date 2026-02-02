#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack is full\n";
            return;
        }

        arr[++top] = val;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow\n";
            return;
        }
        top--;
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[top];
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main(int argc, char const *argv[])
{
    Stack *s = new Stack(5);

    s->push(10);
    s->push(20);
    s->push(30);
    s->pop();
    cout << "Top element of the stack is: " << s->peek();
    return 0;
}
