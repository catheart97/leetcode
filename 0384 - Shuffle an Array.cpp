class Solution
{
private:
    const std::vector<int> & _nums;
    std::mt19937 _engine;
    std::uniform_int_distribution<size_t> _dist;
    
public:
    Solution(const vector<int> & nums) : _nums{nums}, _dist(0, nums.size() - 1) {}
    
    vector<int> reset()
    {
        return std::vector<int>(_nums);
    }
    
    vector<int> shuffle()
    {
        std::vector<int> res(_nums);
        for (size_t i = 0; i < _nums.size(); ++i)
            std::swap(res[i], res[_dist(_engine)]);
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */