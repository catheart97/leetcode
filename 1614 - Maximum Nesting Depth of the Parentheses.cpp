class Solution
{
public:
    int maxDepth(string s) {
        int c_depth = 0;
        int max_depth = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {          
            if (s[i] == '(' && max_depth < ++c_depth)
                max_depth = c_depth;
            else if (s[i] == ')')
                c_depth--;
        }
        return max_depth;
    }
};