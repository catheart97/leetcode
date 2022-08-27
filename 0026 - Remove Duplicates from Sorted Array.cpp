class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int last_number = -101;
        size_t insertation_index = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (int num = nums[i]; last_number != num)
            {
                nums[insertation_index++] = num;
                last_number = num;
            }
        }
        nums.resize(insertation_index + 1);
        return nums.size() - 1;
    }
};