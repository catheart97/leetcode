class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int profit{0}, low, high;

        for (size_t i = 0; i < prices.size() - 1; ++i)
        { 
            low = prices[i];
            while (i < prices.size() - 1 && low >= prices[i + 1])
                low = prices[++i];

            int high = prices[i];
            while (i < prices.size() - 1 && high <= prices[i + 1])
                high = prices[++i];

            profit += high - low;
        }

        return profit;
    }
};