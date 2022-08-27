class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        return std::accumulate(nums.begin() + 1, nums.end(), nums[0], std::bit_xor<int>());
    }
};