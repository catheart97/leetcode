class Solution:
    def pacificAtlantic(self, heights: list):
        m, n = len(heights), len(heights[0])
        p, a = 1, 2
        
        exploration = [ [ 0 for _ in range(n) ] for i in range(m) ]

        def explore(i, j, val):
            if exploration[i][j] == 3 or exploration[i][j] == val:
                return 
            
            h = heights[i][j]
            exploration[i][j] |= val
            
            def _explore(ni, nj):
                onisland = 0 <= ni and ni < m and 0 <= nj and nj < n
                if onisland and h <= heights[ni][nj]: explore(ni, nj, val)
            
            ni, nj = i - 1, j
            _explore(ni, nj)
            ni, nj = i + 1, j
            _explore(ni, nj)
            ni, nj = i, j - 1
            _explore(ni, nj)
            ni, nj = i, j + 1
            _explore(ni, nj)

        for j in range(n - 1):
            explore(0, j, p)
            explore(m - 1, j, a)

        for i in range(m - 1):
            explore(i, 0, p)
            explore(i, n - 1, a)

        explore(0, n - 1, p | a)
        explore(m - 1, 0, p | a)

        return [ [i, j] for i in range(m) for j in range(n) if exploration[i][j] == 3 ]