/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode * p0 = nullptr;
        ListNode * p1 = head;
        
        for (int steps = 1; p1->next; ++steps)
        {
            p1 = p1->next;
            
            if (steps > n - 1)
            {
                if (p0) p0 = p0->next;
                else p0 = head;
            }
        }
        
        if (!p0)
        {
            p0 = head;
            head = head->next;
            delete p0;
        }
        else
        {
            auto to_del = p0->next;
            p0->next = to_del->next;
            delete to_del;
        }
        return head;
    }
};