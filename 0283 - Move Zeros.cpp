class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        size_t insert = 0;
        for (int num : nums)
            if (num) nums[insert++] = num;
        std::fill(nums.begin() + insert, nums.end(), 0);
    }
};