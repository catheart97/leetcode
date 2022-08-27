class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        frequencies = Counter(nums)
        
        partition = []
        for val in frequencies.keys():
            frq = frequencies[val]
            
            for _ in range(frq):             
                for subseq in reversed(partition):
                    if subseq[-1] == val - 1:
                        subseq[0] += 1
                        subseq[1] = val
                        break
                else:
                    partition.append([1, val])
                            
        return all(map(lambda x: x[0] >= 3, partition))