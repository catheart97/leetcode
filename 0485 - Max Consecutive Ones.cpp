class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int max = nums[0], c = nums[0];
        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] == nums[i] && nums[i] == 1)
            {
                c++;
            }
            else if (nums[i] == 1)
            {
                c = 1;
                if (c > max) max = c;
            }
            else
            {
                if (c > max) max = c;
                c = 0;
            }
        }
        if (c > max) max = c;
        return max;
    } 
};