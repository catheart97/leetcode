class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0: return False
        xrev, t = 0, x
        while t:
            xrev, t = xrev * 10 + t % 10, t // 10
        return x == xrev