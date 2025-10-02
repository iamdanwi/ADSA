#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *reverseList(Node *head)
{
    Node *prev = nullptr, *curr = head, *next = nullptr;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = reverseList(head);
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL";
    return 0;
}
