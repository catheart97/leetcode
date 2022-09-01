# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        def goodNodesH(node, value):
            c = 0
            
            if node is None:
                return c
            
            if node.val >= value:
                c += 1
            
            value = max(value, node.val)
            
            c += goodNodesH(node.left, value)
            c += goodNodesH(node.right, value)
            
            return c
        
        return goodNodesH(root, root.val)