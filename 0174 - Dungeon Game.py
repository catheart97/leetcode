class Solution:    
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        n = len(dungeon)
        m = len(dungeon[0])

        dp = [ 0 for _ in range(n * m) ]
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if i + 1 == n and j + 1 == m:
                    if dungeon[i][j] >= 0:
                        dp[i * m + j] = 1  
                    else:
                        dp[i * m + j] = 1 - dungeon[i][j]
                else:
                    if i + 1 < n and j + 1 < m:
                        ans = min(dp[(i + 1) * m + j], dp[i * m + j + 1])
                    elif i + 1 < n:
                        ans = dp[(i + 1) * m + j]
                    else:
                        ans = dp[i * m + j + 1]

                    delta = ans - dungeon[i][j]
                    dp[i * m + j] = max(delta, 1)

        return dp[0]