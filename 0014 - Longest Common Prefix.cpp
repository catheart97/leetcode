class Solution
{
public:
    bool allEqual(vector<string>& strs, size_t char_index)
    {
        if (strs[0].size() <= char_index) return false;

        const char to_cmp{strs[0][char_index]};
        for (size_t i = 0; i < strs.size(); ++i)
        {
            if (strs[i].size() <= char_index) return false;
            if (strs[i][char_index] != to_cmp) return false;
        }
        
        return true;
    }
    
    string longestCommonPrefix(vector<string>& strs)
    {
        size_t commonLength{0};
        while (allEqual(strs, commonLength)) ++commonLength;
        return strs[0].substr(0, commonLength);
    }
};