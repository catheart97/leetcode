class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        target = len(arr) // 2
    
        frequencies = dict()
        for i in arr:
            frequencies[i] = frequencies.get(i, 0) + 1

        frequencies = sorted(frequencies.values(), reverse = True)
            
        partial, removed = 0, 0
        while partial < target: 
            partial += frequencies[removed]
            removed += 1

        return removed
        