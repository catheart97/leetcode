class Solution:
    def median(self, nums : list):
        m = len(nums) // 2
        if len(nums) % 2:
            return nums[m]
        else:
            return (nums[m - 1] + nums[m]) / 2
            
    def medianOf2(self, a, b):
        return (a + b) / 2
    
    def medianOf3(self, a, b, c):
        mx = max(a, max(b, c))
        mn = min(a, min(b, c))
        return (a + b + c - mx - mn)
    
    def medianOf4(self, a, b, c, d):
        mx = max(a, max(b, max(c, d)))
        mn = min(a, min(b, min(c, d)))
        return (a + b + c + d - mn - mx) / 2
    
    def findMedianSortedArraysH(self, nums1: List[int], nums2: List[int]) -> float:    
        
        print(nums1, nums2)
        
        if len(nums1) > len(nums2):
            return self.findMedianSortedArraysH(nums2, nums1)
        
        if len(nums1) == 1:
            if len(nums2) == 1:
                return self.medianOf2(nums1[0], nums2[0])
            elif len(nums2) % 2:
                m = len(nums2) // 2
                return self.medianOf4(nums1[0], nums2[m], nums2[m - 1], nums2[m + 1])
            else:
                m = len(nums2) // 2
                return self.medianOf3(nums1[0], nums2[m], nums2[m - 1])
        elif len(nums1) == 2:
            if len(nums2) == 2:
                return self.medianOf4(*nums1, *nums2)
            elif len(nums2) % 2:
                m = len(nums2) // 2
                return self.medianOf3(nums2[m], max(nums1[1], nums2[m - 1]), min(nums1[0], nums2[m + 1]))
            else:
                m = len(nums2) // 2
                return self.medianOf4(nums2[m], nums2[m - 1], max(nums1[0], nums2[m - 2]), min(nums1[1], nums2[m + 1]))
        else:        
            m1, m2 = (len(nums1) - 1) // 2, (len(nums2) - 1) // 2
            n1, n2 = nums1[m1], nums2[m2]
            if n1 <= n2:
                return self.findMedianSortedArraysH(nums1[m1:], nums2[:len(nums2) - m1])
            else:
                return self.findMedianSortedArraysH(nums1[:len(nums1) - m1], nums2[m1:])
        
    
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:    
        if len(nums1) > 0 and len(nums2) > 0:
            return self.findMedianSortedArraysH(nums1, nums2)
        elif len(nums1) > 0:
            return self.median(nums1)
        else:
            return self.median(nums2)