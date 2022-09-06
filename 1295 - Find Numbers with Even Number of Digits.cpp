class Solution
{
    bool oddDigits(int n)
    {
        int n_digits = 0;
        while (n)
        {
            n = n / 10;
            n_digits++;
        }
        return n_digits % 2;
        
    }
    
public:
    int findNumbers(vector<int>& nums)
    {
        int c = 0;
        for (size_t i = 0; i < nums.size(); ++i)
            if (!oddDigits(nums[i])) c++;
        return c;
    }
};