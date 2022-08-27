class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        for (size_t i = 0; i < s.size() / 2; ++i)
        {
            const auto tmp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = tmp;
        }
    }
};