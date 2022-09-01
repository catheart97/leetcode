class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [ -1 ] * n
        
        def explore(n):
            
            if n == 0: return 1
            if n < 0: return 0
            
            if dp[n - 1] != -1:
                return dp[n - 1]
            
            dp[n - 1] = explore(n - 2) + explore(n - 1)
            return dp[n - 1]
                
        return explore(n)