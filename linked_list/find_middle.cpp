#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *findMiddle(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *slow = head, *fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *middle = findMiddle(head);
    std::cout << "Middle element: " << middle->data;
    return 0;
}
