# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:    
    
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        carrybit = 0
        l1p, l2p = l1, l2
        r, rp = None, None
        
        while l1p is not None and l2p is not None:
            tmp = carrybit + l1p.val + l2p.val
            carrybit = tmp // 10
            node = ListNode(tmp % 10)
            if r is None:
                r, rp = node, node
            else:
                rp.next, rp = node, node
            l1p, l2p = l1p.next, l2p.next
            
        if l1p is None:
            l1p = l2p
            l2p = None
            
        while l1p is not None:
            tmp = carrybit + l1p.val
            carrybit = tmp // 10
            node = ListNode(tmp % 10)
            if r is None:
                r, rp = node, node
            else:
                rp.next, rp = node, node  
            l1p = l1p.next
                
        if carrybit:
            rp.next = ListNode(carrybit)
                
        return r