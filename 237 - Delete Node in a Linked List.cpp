/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node)
    {
        auto nodep{node};
        
        while (nodep->next->next)
        {
            nodep->val = nodep->next->val;
            nodep = nodep->next;
        }
        
        nodep->val = nodep->next->val;
        delete nodep->next;
        nodep->next = nullptr;
    }
};