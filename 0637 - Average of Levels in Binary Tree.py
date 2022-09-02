# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def join(self, a, b):
        if len(a) < len(b): a, b = b, a
        for i in range(len(b)):
            t = a[i][1] + b[i][1]
            a[i] = ( a[i][0] * a[i][1]/t + b[i][0] * b[i][1]/t,  a[i][1] + b[i][1])
        return a
    
    def averageOfLevelsH(self, root: Optional[TreeNode]):
        r1, r2 = [], []
        if root.left  is not None: r1 = self.averageOfLevelsH(root.left)
        if root.right is not None: r2 = self.averageOfLevelsH(root.right)
        return [ (root.val, 1) ] + self.join(r1, r2)
    
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        r1, r2 = [], []
        if root.left  is not None: r1 = self.averageOfLevelsH(root.left)
        if root.right is not None: r2 = self.averageOfLevelsH(root.right)
        return [ root.val ] + [ x[0] for x in self.join(r1, r2) ]