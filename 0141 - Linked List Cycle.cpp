/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        auto rabbit = head;
        auto turtle = head;
        
        while (rabbit && rabbit->next && turtle)
        {
            rabbit = rabbit->next->next;
            turtle = turtle->next;
            
            if (rabbit == turtle)
                return true;
        }
        
        return false;
    }
};