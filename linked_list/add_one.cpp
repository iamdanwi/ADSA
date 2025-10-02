#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

Node *addOne(Node *head)
{
    if (!head)
        return new Node(1);

    Node *curr = head;
    Node *last_not_nine = nullptr;

    while (curr)
    {
        if (curr->data != 9)
        {
            last_not_nine = curr;
        }
        curr = curr->next;
    }

    if (last_not_nine)
    {
        last_not_nine->data++;
        curr = last_not_nine->next;
        while (curr)
        {
            curr->data = 0;
            curr = curr->next;
        }
    }
    else
    {
        Node *new_head = new Node(1);
        curr = head;
        while (curr)
        {
            curr->data = 0;
            curr = curr->next;
        }
        new_head->next = head;
        return new_head;
    }
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);

    head = addOne(head);
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
