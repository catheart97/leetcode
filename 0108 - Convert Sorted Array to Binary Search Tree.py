# Definition for a binary tree node.
from tkinter.tix import Tree


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def sortedArrayToBST(self, nums: list) -> TreeNode:
        if len(nums) == 0:
            return None 
        if len(nums) == 1:
            return TreeNode(nums[0])
        
        m = len(nums) // 2
        l = nums[:m]
        r = nums[m+1:]

        return TreeNode(nums[m], self.sortedArrayToBST(l), self.sortedArrayToBST(r))
        