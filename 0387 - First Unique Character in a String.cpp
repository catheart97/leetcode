class Solution
{
public:
    int firstUniqChar(string s)
    {
        std::unordered_map<char, int> counts;
        for (size_t i = 0; i < s.size(); ++i)
            counts[s[i]] += 1;
        for (size_t i = 0; i < s.size(); ++i)
            if (counts[s[i]] == 1) return i;
        return -1;
    }
};