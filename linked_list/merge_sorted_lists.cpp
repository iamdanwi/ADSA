#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;

    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    curr->next = l1 ? l1 : l2;
    return dummy->next;
}

int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    ListNode *result = mergeTwoLists(l1, l2);
    while (result)
    {
        std::cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
