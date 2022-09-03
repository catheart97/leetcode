class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> list:
        solutions = []
        
        def findSolutions(m):
            
            if (m // 10**(n - 1)) > 0: # check if number of digits in m reached n
                return solutions.append(m)
                
            ld = (m % 10) # get last digit added
            
            # check if last digit + k is a valid next digit
            nd = ld + k 
            if  0 <= nd and nd < 10:
                findSolutions(m * 10 + nd)
            
            # check if last digit - k is a valid next digit
            nd = ld - k
            if  k and 0 <= nd and nd < 10:
                findSolutions(m * 10 + nd)
            
        # starting digit in {1, ..., 9}
        for d in range(1, 10): findSolutions(d)
        
        return solutions


print(Solution().numsSameConsecDiff(2, 1))