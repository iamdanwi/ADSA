#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *curr = head;

    while (curr && curr->next)
    {
        if (curr->val == curr->next->val)
        {
            ListNode *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    head = deleteDuplicates(head);
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
