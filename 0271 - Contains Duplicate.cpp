class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        std::unordered_map<int, int> occurances;
        for (const int n : nums)
        {
            if (occurances.find(n) != occurances.end())
                return true;
            occurances[n] = 42;
        }
        return false;
    }
};