class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        const int N {static_cast<int>(nums.size())};
        int sum {(N * N + N) / 2}; // gauß
        for (size_t i = 0; i < nums.size(); ++i)
            sum -= nums[i];
        return sum;
    }
};