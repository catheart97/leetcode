class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        std::unordered_map<int, int> counts1;
        std::unordered_map<int, int> counts2;

        for (int i = 0; i < nums1.size(); ++i) counts1[nums1[i]] += 1;
        for (int i = 0; i < nums2.size(); ++i) counts2[nums2[i]] += 1;

        std::vector<int> result;
        for (auto val : counts1)
        {
            auto to_add = std::min(
                val.second,
                counts2.find(val.first) != counts2.end() ? counts2[val.first] : 0
            );
            result.resize(result.size() + to_add, val.first);
        }

        return std::move(result);
    }
};