#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
        return nullptr;

    ListNode *a = headA, *b = headB;

    while (a != b)
    {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

int main()
{
    ListNode *commonNode = new ListNode(8);
    commonNode->next = new ListNode(4);
    commonNode->next->next = new ListNode(5);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = commonNode;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = commonNode;

    ListNode *result = getIntersectionNode(headA, headB);
    if (result)
        std::cout << "Intersection at node with value: " << result->val;
    else
        std::cout << "No intersection";
    return 0;
}
