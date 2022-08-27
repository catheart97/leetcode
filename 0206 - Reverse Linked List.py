# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p, x = None, head
        while x is not None:
            t = x.next
            p, x.next = x, p
            x = t
        return p