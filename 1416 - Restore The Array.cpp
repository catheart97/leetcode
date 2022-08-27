class Solution
{
private:
    const int MODULO = 1e9+7;

    int numberOfArraysHelper(const std::string & s, const int k, std::vector<int> &dp, const int i = 0)
    {
        if ( i == s.size() ) return 1;
        if ( dp[i] != -1 ) return dp[i];
        if ( s[i] == '0' ) return 0;
        
        long long val = 0;
        int res = 0;
        
        for (int j = i; j < s.size(); ++j)
        {
            val = 10 * val + (s[j] - 48);
            if (val > k) break;
            res = (res + numberOfArraysHelper(s, k, dp, j + 1)) % MODULO;
        }
        
        return dp[i] = res;
    }
    
public:
    int numberOfArrays(string s, int k)
    {
        std::vector<int> dp(s.size() + 1, -1);
        return numberOfArraysHelper(s, k, dp);
    }
};