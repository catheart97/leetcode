class Solution:
    def reverse(self, nums: List[int], start : int, end : int) -> None:
        for i in range(start, start + (end - start) // 2):
            nums[ i ], nums[ end - (i - start) - 1 ] = nums[ end - (i - start) - 1 ], nums[ i ]
        
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % len(nums) # minify problem
        self.reverse(nums, 0, n - k)
        self.reverse(nums, n - k, n)
        self.reverse(nums, 0, n)