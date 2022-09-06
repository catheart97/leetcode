"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def join(self, a, b):
        if len(a) < len(b):
            for i in range(len(a)): b[i] = a[i] + b[i]
            return b
        else:
            for i in range(len(b)): a[i] += b[i]
            return a
    
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        res = []
        if root is None: return res
        for c in root.children: res = self.join(res, self.levelOrder(c))
        return [[root.val]] + res
