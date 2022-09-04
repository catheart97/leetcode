class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int profit{0}, low{std::numeric_limits<int>::max()}, potential{0};
        for (size_t i = 0; i < prices.size(); ++i)
        { 
            if (prices[i] < low) low = prices[i];
            potential = prices[i] - low;
            if (profit < potential) profit = potential;
        }

        return profit;
    }
};