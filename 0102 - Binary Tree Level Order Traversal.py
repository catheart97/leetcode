# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None: 
            return []
        
        m = [[root.val]] + self.levelOrder(root.left)
        r = self.levelOrder(root.right)
        for i in range(0, len(r)):
            if i + 1 < len(m):
                m[i + 1] += r[i]
            else:
                m.append(r[i])
        
        return m