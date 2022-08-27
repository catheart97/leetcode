class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) return false;
        
        std::unordered_map<char, int> counts; // for unicode characters: wchar and 
        std::unordered_map<char, int> countt; // wstring
        
        for (size_t i = 0; i < s.size(); ++i)
            counts[s[i]] += 1;
    
        for (size_t i = 0; i < t.size(); ++i)
            countt[t[i]] += 1;
    
        for (const auto v : counts)
            if (v.second != countt[v.first]) return false;
        return true;
    }
};