class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        dp = [ [ [ -1  for _ in range(n) ] for _ in range(n) ] for _ in range(n) ] 
        
        def cherryWalk(p1i, p1j, p2i):
            # compute remaining index p1i+p1j == p2i+p2j
            p2j = p1i + p1j - p2i  
        
            # check if out of bounds
            if p1i == n or p1j == n or p2i == n or p2j == n: return -2
            
            # check if both walkable
            if grid[p1i][p1j] == -1 or grid[p2i][p2j] == -1: return -2

            # if already computed => return from memory
            if dp[p1i][p1j][p2i] != -1: return dp[p1i][p1j][p2i]
            
            # let both pick their cherries 
            cherries_picked = grid[p1i][p1j]
            if not (p1i == p2i and p1j == p2j):
                cherries_picked += grid[p2i][p2j]
            
            # compute all ongoing cases (inclusive edge case)
            if p1i == n - 1 and p1j == n - 1: return cherries_picked
            n0 = cherryWalk(p1i, p1j + 1, p2i + 1) 
            n1 = cherryWalk(p1i + 1, p1j, p2i + 1) 
            n2 = cherryWalk(p1i, p1j + 1, p2i) 
            n3 = cherryWalk(p1i + 1, p1j, p2i) 
            
            # if none of these is valid this is not valid as well
            tbp = max([n0, n1, n2, n3])
            if tbp == -2:
                cherries_picked = 0
            
            # return result
            cherries_picked = cherries_picked + tbp
            dp[p1i][p1j][p2i] = cherries_picked
            return cherries_picked
        
        return max(cherryWalk(0, 0, 0), 0)