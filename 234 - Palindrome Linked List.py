# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    
    def reverseLinkedList(self, head: ListNode) -> ListNode:
        p, x = None, head
        while x is not None:
            t = x.next
            p, x.next = x, p
            x = t
        return p
    
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        
        # compute center (if odd ignore center)
        t, p1, p2 = None, head, head
        while p2 is not None:
            p2, t, p1 = p2.next, p1, p1.next
            if p2 is not None:
                p2 = p2.next
        t.next = None
        
        # reverse second half 
        p1 = self.reverseLinkedList(p1)
        p2 = head
        
        # compare if both segments are equal
        while p1 is not None:
            if p1.val != p2.val:
                return False
            p1, p2 = p1.next, p2.next
        
        return True