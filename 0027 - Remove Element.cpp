class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        size_t k{0};
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == val)
                continue;
            
            nums[k++] = nums[i];
        }
        
        return k;
    }
};
