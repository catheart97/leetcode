class Solution
{
public:
    int maxProfit(int k, std::vector<int>& prices) 
    {
        std::vector<int> dp( 2 * k + 1, std::numeric_limits<int>::lowest() );
        dp[0] = 0;
        
        for(size_t i = 0; i < prices.size(); ++i)
        {
            for(size_t j = 0; j + 2 <= 2 * k; ++++j)
            {
                dp[j + 1] = max(dp[j + 1], dp[j    ] - prices[i]);
                dp[j + 2] = max(dp[j + 2], dp[j + 1] + prices[i]);
            }
        }
        
        return *std::max_element(dp.begin(), dp.end());    
    }
};