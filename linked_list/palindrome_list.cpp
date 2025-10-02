#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode *head)
{
    if (!head || !head->next)
        return true;

    ListNode *slow = head, *fast = head;
    ListNode *prev = nullptr;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        ListNode *temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    if (fast)
        slow = slow->next;

    while (prev && slow)
    {
        if (prev->val != slow->val)
            return false;
        prev = prev->next;
        slow = slow->next;
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    std::cout << (isPalindrome(head) ? "Palindrome" : "Not Palindrome");
    return 0;
}
