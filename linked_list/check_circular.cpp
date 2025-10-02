#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

bool isCircular(Node *head)
{
    if (!head)
        return false;

    Node *temp = head->next;
    while (temp && temp != head)
    {
        temp = temp->next;
    }
    return (temp == head);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head; // Making it circular

    std::cout << (isCircular(head) ? "Circular" : "Not Circular");
    return 0;
}
