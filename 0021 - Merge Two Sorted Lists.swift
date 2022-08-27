
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
}

class Solution
{
    func mergeTwoLists(_ list1: ListNode?, _ list2: ListNode?) -> ListNode?
    {
        if list1 == nil && list2 == nil 
        {
            return nil
        }
        else if list1 == nil
        {
            return list2
        }
        else if list2 == nil
        {
            return list1 
        }
        else
        {
            var l1 = list1
            var l2 = list2
            
            if (l1!.val > l2!.val)
            {
                swap(&l1, &l2)
            }

            let root = l1!
            var rp = root
            l1 = l1!.next

            while l1 != nil && l2 != nil
            {
                if (l1!.val < l2!.val)
                {
                    rp.next = l1
                    rp = rp.next!
                    l1 = l1!.next
                }
                else 
                {
                    rp.next = l2
                    rp = rp.next!
                    l2 = l2!.next
                }
            }

            if l1 == nil
            {
                swap(&l1, &l2)
            }
            rp.next = l1

            return root
        }
    }
}