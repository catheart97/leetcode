class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> dict;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (dict.find(nums[i]) != dict.end() && dict[nums[i]] != i)
                return {i, dict[nums[i]]};  
            dict[target - nums[i]] = i;
        }
        return std::vector<int>();
    }
};