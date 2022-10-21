class Solution
{
public:
    bool containsNearbyDuplicate(const vector<int>& nums, const int k)
    {
        std::unordered_map<int, size_t> last;
        
        for (size_t i = 0; i < nums.size(); ++i)
        {
            const int n = nums[i];
            if (auto it = last.find(n); it != last.end() && i - it->second <= k) 
                return true;
            last[n] = i;
        }
        
        return false;
    }
};