class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 1) return std::vector<std::vector<int>>{std::vector<int>{1}};
        
        std::vector<std::vector<int>> triangle{
            std::vector<int>{1},
            std::vector<int>{1, 1}
        };
        
        for (size_t i = 0; i < numRows - 2; ++i)
        {
            auto & prev{triangle[triangle.size() - 1]};
            std::vector<int> values(prev.size() + 1);
            values[0] = values[values.size() - 1] =  1;
            for (size_t j = 1; j < values.size() - 1; ++j)
                values[j] = prev[j - 1] + prev[j];
            triangle.push_back(std::move(values));
        }
        
        return triangle;
    }
};