void merge(int* nums1, const int nums1Size, const int m, int* nums2, const int nums2Size, const int n)
{
    int i = m - 1, j = n - 1;
    int p = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] < nums2[j])
            nums1[p--] = nums2[j--];
        else 
            nums1[p--] = nums1[i--];
    }
    while (j >= 0)
        nums1[p--] = nums2[j--];
}